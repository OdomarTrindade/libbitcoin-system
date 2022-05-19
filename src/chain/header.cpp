/**
 * Copyright (c) 2011-2019 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <bitcoin/system/chain/header.hpp>

#include <chrono>
#include <cstddef>
#include <utility>
#include <boost/json.hpp>
#include <bitcoin/system/chain/chain_state.hpp>
#include <bitcoin/system/chain/compact.hpp>
#include <bitcoin/system/constants.hpp>
#include <bitcoin/system/crypto/crypto.hpp>
#include <bitcoin/system/data/data.hpp>
#include <bitcoin/system/error/error.hpp>
#include <bitcoin/system/stream/stream.hpp>

namespace libbitcoin {
namespace system {
namespace chain {

// Use system clock because we require accurate time of day.
using wall_clock = std::chrono::system_clock;

// Constructors.
// ----------------------------------------------------------------------------

header::header() noexcept
  : header(0, {}, {}, 0, 0, 0, false)
{
}

header::header(header&& other) noexcept
: header(
    other.version_,
    std::move(other.previous_block_hash_),
    std::move(other.merkle_root_),
    other.timestamp_,
    other.bits_,
    other.nonce_,
    other.valid_)
{
}

header::header(const header& other) noexcept
: header(
    other.version_,
    other.previous_block_hash_,
    other.merkle_root_,
    other.timestamp_,
    other.bits_,
    other.nonce_,
    other.valid_)
{
}

header::header(uint32_t version, hash_digest&& previous_block_hash,
    hash_digest&& merkle_root, uint32_t timestamp, uint32_t bits,
    uint32_t nonce) noexcept
  : header(version, std::move(previous_block_hash), std::move(merkle_root),
      timestamp, bits, nonce, true)
{
}

header::header(uint32_t version, const hash_digest& previous_block_hash,
    const hash_digest& merkle_root, uint32_t timestamp, uint32_t bits,
    uint32_t nonce) noexcept
  : header(version, previous_block_hash, merkle_root, timestamp, bits, nonce,
      true)
{
}

header::header(const data_slice& data) noexcept
  : header(stream::in::copy(data))
{
}

header::header(std::istream&& stream) noexcept
  : header(read::bytes::istream(stream))
{
}

header::header(std::istream& stream) noexcept
  : header(read::bytes::istream(stream))
{
}

header::header(reader&& source) noexcept
  : header(from_data(source))
{
}

header::header(reader& source) noexcept
  : header(from_data(source))
{
}

// protected
header::header(uint32_t version, hash_digest&& previous_block_hash,
    hash_digest&& merkle_root, uint32_t timestamp, uint32_t bits,
    uint32_t nonce, bool valid) noexcept
  : version_(version),
    previous_block_hash_(std::move(previous_block_hash)),
    merkle_root_(std::move(merkle_root)),
    timestamp_(timestamp),
    bits_(bits),
    nonce_(nonce),
    valid_(valid)
{
}

// protected
header::header(uint32_t version, const hash_digest& previous_block_hash,
    const hash_digest& merkle_root, uint32_t timestamp, uint32_t bits,
    uint32_t nonce, bool valid) noexcept
  : version_(version),
    previous_block_hash_(previous_block_hash),
    merkle_root_(merkle_root),
    timestamp_(timestamp),
    bits_(bits),
    nonce_(nonce),
    valid_(valid)
{
}

// Operators.
// ----------------------------------------------------------------------------

header& header::operator=(header&& other) noexcept
{
    version_ = other.version_;
    previous_block_hash_ = std::move(other.previous_block_hash_);
    merkle_root_ = std::move(other.merkle_root_);
    timestamp_ = other.timestamp_;
    bits_ = other.bits_;
    nonce_ = other.nonce_;
    valid_ = other.valid_;
    return *this;
}

header& header::operator=(const header& other) noexcept
{
    version_ = other.version_;
    previous_block_hash_ = other.previous_block_hash_;
    merkle_root_ = other.merkle_root_;
    timestamp_ = other.timestamp_;
    bits_ = other.bits_;
    nonce_ = other.nonce_;
    valid_ = other.valid_;
    return *this;
}

bool header::operator==(const header& other) const noexcept
{
    return (version_ == other.version_)
        && (previous_block_hash_ == other.previous_block_hash_)
        && (merkle_root_ == other.merkle_root_)
        && (timestamp_ == other.timestamp_)
        && (bits_ == other.bits_)
        && (nonce_ == other.nonce_);
}

bool header::operator!=(const header& other) const noexcept
{
    return !(*this == other);
}

// Deserialization.
// ----------------------------------------------------------------------------

// static/private
header header::from_data(reader& source) noexcept
{
    return
    {
        source.read_4_bytes_little_endian(),
        source.read_hash(),
        source.read_hash(),
        source.read_4_bytes_little_endian(),
        source.read_4_bytes_little_endian(),
        source.read_4_bytes_little_endian(),
        source
    };
}

// Serialization.
// ----------------------------------------------------------------------------

data_chunk header::to_data() const noexcept
{
    data_chunk data(no_fill_byte_allocator);
    data.resize(serialized_size());
    stream::out::copy ostream(data);
    to_data(ostream);
    return data;
}

void header::to_data(std::ostream& stream) const noexcept
{
    write::bytes::ostream out(stream);
    to_data(out);
}

void header::to_data(writer& sink) const noexcept
{
    sink.write_4_bytes_little_endian(version_);
    sink.write_bytes(previous_block_hash_);
    sink.write_bytes(merkle_root_);
    sink.write_4_bytes_little_endian(timestamp_);
    sink.write_4_bytes_little_endian(bits_);
    sink.write_4_bytes_little_endian(nonce_);
}

// Properties.
// ----------------------------------------------------------------------------

bool header::is_valid() const noexcept
{
    return valid_;
}

uint32_t header::version() const noexcept
{
    return version_;
}

const hash_digest& header::previous_block_hash() const noexcept
{
    return previous_block_hash_;
}

const hash_digest& header::merkle_root() const noexcept
{
    return merkle_root_;
}

uint32_t header::timestamp() const noexcept
{
    return timestamp_;
}

uint32_t header::bits() const noexcept
{
    return bits_;
}

uint32_t header::nonce() const noexcept
{
    return nonce_;
}

// computed
hash_digest header::hash() const noexcept
{
    hash_digest sha256;
    hash::sha256::copy sink(sha256);
    to_data(sink);
    sink.flush();
    return sha256_hash(sha256);
}

// static/private
uint256_t header::difficulty(uint32_t bits) noexcept
{
    const auto header_bits = compact(bits);

    if (header_bits.is_overflowed())
        return zero;

    // We need to compute 2**256 / (target + 1), but we can't represent 2**256
    // as it's too large for uint256. However as 2**256 is at least as large as
    // target + 1, it is equal to ((2**256 - target - 1) / (target + 1)) + 1, or
    // (~target / (target + 1)) + 1.

    uint256_t target(header_bits);
    const auto divisor = add1(target);

    //*************************************************************************
    // CONSENSUS: satoshi will throw division by zero in the case where the
    // target is (2^256)-1 as the overflow will result in a zero divisor.
    // While actually achieving this work is improbable, this method operates
    // on a public method and therefore must be guarded.
    //*************************************************************************
    return is_zero(divisor) ? zero : add1(~target / divisor);
}

// computed
uint256_t header::difficulty() const noexcept
{
    return difficulty(bits_);
}

// static
size_t header::serialized_size() noexcept
{
    return sizeof(version_)
        + hash_size
        + hash_size
        + sizeof(timestamp_)
        + sizeof(bits_)
        + sizeof(nonce_);
}

// Check.
// ----------------------------------------------------------------------------

bool header::is_invalid_proof_of_work(uint32_t proof_of_work_limit,
    bool scrypt) const noexcept
{
    const auto bits = compact(bits_);
    static const uint256_t pow_limit(compact{ proof_of_work_limit });

    if (bits.is_overflowed())
        return true;

    uint256_t target(bits);

    // Ensure claimed work is within limits.
    if (target < one || target > pow_limit)
        return true;

    // Conditionally use scrypt proof of work (e.g. Litecoin).
    // Ensure actual work is at least claimed amount (smaller is more work).
    return to_uint256(scrypt ? scrypt_hash(to_data()) : hash()) > target;
}

// ****************************************************************************
/// CONSENSUS: bitcoin 32bit unix time: en.wikipedia.org/wiki/Year_2038_problem
// ****************************************************************************
bool header::is_invalid_timestamp(
    uint32_t timestamp_limit_seconds) const noexcept
{
    using namespace std::chrono;
    static const auto two_hours = seconds(timestamp_limit_seconds);
    const auto time = wall_clock::from_time_t(timestamp_);
    const auto future = wall_clock::now() + two_hours;
    return time > future;
}

// Validation.
// ----------------------------------------------------------------------------

code header::check(uint32_t timestamp_limit_seconds,
    uint32_t proof_of_work_limit, bool scrypt) const noexcept
{
    if (is_invalid_proof_of_work(proof_of_work_limit, scrypt))
        return error::invalid_proof_of_work;

    if (is_invalid_timestamp(timestamp_limit_seconds))
        return error::futuristic_timestamp;

    return error::success;
}

code header::accept(const chain_state& state) const noexcept
{
    if (state.is_checkpoint_conflict(hash()))
        return error::checkpoints_failed;

    if (version_ < state.minimum_block_version())
        return error::invalid_block_version;

    if (timestamp_ <= state.median_time_past())
        return error::timestamp_too_early;

    if (bits_ != state.work_required())
        return error::incorrect_proof_of_work;

    return error::success;
}

// JSON value convertors.
// ----------------------------------------------------------------------------

namespace json = boost::json;

header tag_invoke(json::value_to_tag<header>,
    const json::value& value) noexcept
{
    hash_digest previous, merkle_root;
    if (!decode_hash(previous, value.at("previous").get_string().c_str()) ||
        !decode_hash(merkle_root, value.at("merkle_root").get_string().c_str()))
        return {};

    return
    {
        value.at("version").to_number<uint32_t>(),
        previous,
        merkle_root,
        value.at("timestamp").to_number<uint32_t>(),
        value.at("bits").to_number<uint32_t>(),
        value.at("nonce").to_number<uint32_t>()
    };
}

void tag_invoke(json::value_from_tag, json::value& value,
    const header& tx) noexcept
{
    value =
    {
        { "version", tx.version() },
        { "previous", encode_hash(tx.previous_block_hash()) },
        { "merkle_root", encode_hash(tx.merkle_root()) },
        { "timestamp", tx.timestamp() },
        { "bits", tx.bits() },
        { "nonce", tx.nonce() }
    };
}

header::ptr tag_invoke(json::value_to_tag<header::ptr>,
    const json::value& value) noexcept
{
    return to_shared(tag_invoke(json::value_to_tag<header>{}, value));
}

void tag_invoke(json::value_from_tag tag, json::value& value,
    const header::ptr& tx) noexcept
{
    tag_invoke(tag, value, *tx);
}

} // namespace chain
} // namespace system
} // namespace libbitcoin
