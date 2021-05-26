/**
 * Copyright (c) 2011-2021 libbitcoin developers (see AUTHORS)
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
#include "../../test.hpp"
#include <sstream>
#include <utility>
#include "electrum_v1.hpp"

BOOST_AUTO_TEST_SUITE(electrum_v1_tests)

using namespace test::mnemonics_electrum_v1;
using namespace bc::system::wallet;

#define TODO_TESTS true
#define PUBLIC_STATIC 1
#define PROTECTED_STATIC 1
#define CONSTRUCTORS 1
#define PUBLIC_METHODS 1
#define OPERATORS 1
#define VERIFIED_VECTORS 1

#ifdef PUBLIC_STATIC

// contained_by

BOOST_AUTO_TEST_CASE(electrum_v1__contained_by__empty_any__true)
{
    // This is based on the order of dictionary insertion (first).
    BOOST_REQUIRE(electrum_v1::contained_by({}) == language::en);
}

BOOST_AUTO_TEST_CASE(electrum_v1__contained_by__invalid_any__none)
{
    BOOST_REQUIRE(electrum_v1::contained_by({ "foo" }) == language::none);
}

BOOST_AUTO_TEST_CASE(electrum_v1__contained_by__yellow_lotus__none)
{
    // en and pt words
    BOOST_REQUIRE(electrum_v1::contained_by({ "yellow", "lotus" }) == language::none);
}

BOOST_AUTO_TEST_CASE(electrum_v1__contained_by__blind_faith__en)
{
    BOOST_REQUIRE(electrum_v1::contained_by(words2) == language::en);
}

BOOST_AUTO_TEST_CASE(electrum_v1__contained_by__explicit_language__expected)
{
    BOOST_REQUIRE(electrum_v1::contained_by(words2, language::en) == language::en);
}

BOOST_AUTO_TEST_CASE(electrum_v1__contained_by__incorrect_explicit_language__none)
{
    BOOST_REQUIRE(electrum_v1::contained_by(words2, language::pt) == language::none);
}

BOOST_AUTO_TEST_CASE(electrum_v1__contained_by__invalid_explicit_language__none)
{
    BOOST_REQUIRE(electrum_v1::contained_by(words2, language::ko) == language::none);
}

// is_valid_dictionary

BOOST_AUTO_TEST_CASE(electrum_v1__is_valid_dictionary__contained__true)
{
    BOOST_REQUIRE(electrum_v1::is_valid_dictionary(language::en));
    BOOST_REQUIRE(electrum_v1::is_valid_dictionary(language::pt));
}

BOOST_AUTO_TEST_CASE(electrum_v1__is_valid_dictionary__uncontained__false)
{
    BOOST_REQUIRE(!electrum_v1::is_valid_dictionary(language::es));
    BOOST_REQUIRE(!electrum_v1::is_valid_dictionary(language::it));
    BOOST_REQUIRE(!electrum_v1::is_valid_dictionary(language::fr));
    BOOST_REQUIRE(!electrum_v1::is_valid_dictionary(language::cs));
    BOOST_REQUIRE(!electrum_v1::is_valid_dictionary(language::ja));
    BOOST_REQUIRE(!electrum_v1::is_valid_dictionary(language::ko));
    BOOST_REQUIRE(!electrum_v1::is_valid_dictionary(language::zh_Hans));
    BOOST_REQUIRE(!electrum_v1::is_valid_dictionary(language::zh_Hant));
    BOOST_REQUIRE(!electrum_v1::is_valid_dictionary(language::none));
}

// is_valid_entropy_size

BOOST_AUTO_TEST_CASE(electrum_v1__is_valid_entropy_size__valid__true)
{
    BOOST_REQUIRE(electrum_v1::is_valid_entropy_size(16));
    BOOST_REQUIRE(electrum_v1::is_valid_entropy_size(32));
}

BOOST_AUTO_TEST_CASE(electrum_v1__is_valid_entropy_size__invalid__false)
{
    BOOST_REQUIRE(!electrum_v1::is_valid_entropy_size(0));
    BOOST_REQUIRE(!electrum_v1::is_valid_entropy_size(8));
    BOOST_REQUIRE(!electrum_v1::is_valid_entropy_size(15));
    BOOST_REQUIRE(!electrum_v1::is_valid_entropy_size(17));
    BOOST_REQUIRE(!electrum_v1::is_valid_entropy_size(31));
    BOOST_REQUIRE(!electrum_v1::is_valid_entropy_size(33));
    BOOST_REQUIRE(!electrum_v1::is_valid_entropy_size(64));
}

// is_valid_word_count

BOOST_AUTO_TEST_CASE(electrum_v1__is_valid_word_count__valid__true)
{
    BOOST_REQUIRE(electrum_v1::is_valid_word_count(12));
    BOOST_REQUIRE(electrum_v1::is_valid_word_count(24));
}

BOOST_AUTO_TEST_CASE(electrum_v1__is_valid_word_count__invalid__false)
{
    BOOST_REQUIRE(!electrum_v1::is_valid_word_count(0));
    BOOST_REQUIRE(!electrum_v1::is_valid_word_count(3));
    BOOST_REQUIRE(!electrum_v1::is_valid_word_count(6));
    BOOST_REQUIRE(!electrum_v1::is_valid_word_count(9));
    BOOST_REQUIRE(!electrum_v1::is_valid_word_count(15));
    BOOST_REQUIRE(!electrum_v1::is_valid_word_count(18));
    BOOST_REQUIRE(!electrum_v1::is_valid_word_count(27));
}

#endif // PUBLIC_STATIC

#ifdef PROTECTED_STATIC

// coders
// ----------------------------------------------------------------------------

// encoder

BOOST_AUTO_TEST_CASE(electrum_v1__encoder__todo__todo)
{
    BOOST_REQUIRE(TODO_TESTS);
}

// decoder

BOOST_AUTO_TEST_CASE(electrum_v1__decoder__todo__todo)
{
    BOOST_REQUIRE(TODO_TESTS);
}

// sizers
// ----------------------------------------------------------------------------

// entropy_bits1

BOOST_AUTO_TEST_CASE(electrum_v1__entropy_bits1__todo__todo)
{
    BOOST_REQUIRE(TODO_TESTS);
}

// entropy_bits2

BOOST_AUTO_TEST_CASE(electrum_v1__entropy_bits2__todo__todo)
{
    BOOST_REQUIRE(TODO_TESTS);
}

// entropy_size

BOOST_AUTO_TEST_CASE(electrum_v1__entropy_size__todo__todo)
{
    BOOST_REQUIRE(TODO_TESTS);
}

// word_count

BOOST_AUTO_TEST_CASE(electrum_v1__word_count__todo__todo)
{
    BOOST_REQUIRE(TODO_TESTS);
}


// factories
// ----------------------------------------------------------------------------

// from_entropy

BOOST_AUTO_TEST_CASE(electrum_v1__from_entropy__todo__todo)
{
    BOOST_REQUIRE(TODO_TESTS);
}

// from_words

BOOST_AUTO_TEST_CASE(electrum_v1__from_words__todo__todo)
{
    BOOST_REQUIRE(TODO_TESTS);
}

#endif // PROTECTED_STATIC

#ifdef CONSTRUCTORS

// construct default

BOOST_AUTO_TEST_CASE(electrum_v1__construct_default__always__invalid)
{
    BOOST_REQUIRE(!electrum_v1());
}

// construct copy

BOOST_AUTO_TEST_CASE(electrum_v1__construct_copy__always__expected)
{
    electrum_v1 instance1(join(words12));
    const electrum_v1 instance2(instance1);
    BOOST_REQUIRE(instance2);
    BOOST_REQUIRE_EQUAL(instance2.words(), words12);
    BOOST_REQUIRE_EQUAL(instance2.entropy(), instance1.entropy());
    BOOST_REQUIRE(instance2.lingo() == instance1.lingo());
}

// construct move (default)

BOOST_AUTO_TEST_CASE(electrum_v1__construct_move__always__expected)
{
    electrum_v1 instance1(join(words12));
    const electrum_v1 instance2(std::move(instance1));
    BOOST_REQUIRE(instance2);
    BOOST_REQUIRE_EQUAL(instance2.words(), words12);
    BOOST_REQUIRE_EQUAL(instance2.entropy(), instance1.entropy());
    BOOST_REQUIRE(instance2.lingo() == instance1.lingo());
}

// construct sentence

BOOST_AUTO_TEST_CASE(electrum_v1__construct_sentence__empty_sentence__invalid)
{
    BOOST_REQUIRE(!electrum_v1(""));
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_sentence__2_word_sentence__invalid_empty)
{
    const electrum_v1 instance(join(words2));
    BOOST_REQUIRE(!instance);
    BOOST_REQUIRE(instance.sentence().empty());
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_sentence__12_word_sentence__valid_expected)
{
    const electrum_v1 instance(join(words12));
    BOOST_REQUIRE(instance);
    BOOST_REQUIRE_EQUAL(instance.sentence(), join(words12));
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_sentence__24_word_sentence__valid_expected)
{
    const electrum_v1 instance(join(words24));
    BOOST_REQUIRE(instance);
    BOOST_REQUIRE_EQUAL(instance.sentence(), join(words24));
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_sentence__26_word_sentence__valid_expected)
{
    const electrum_v1 instance(words26);
    BOOST_REQUIRE(!instance);
    BOOST_REQUIRE(instance.sentence().empty());
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_sentence__explicit_language__valid_expected)
{
    const electrum_v1 instance(join(words12), language::en);
    BOOST_REQUIRE(instance);
    BOOST_REQUIRE_EQUAL(instance.sentence(), join(words12));
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_sentence__incorrect_language__invalid)
{
    const electrum_v1 instance(join(words24), language::pt);
    BOOST_REQUIRE(!instance);
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_sentence__invalid_language__invalid)
{
    const electrum_v1 instance(join(words24), language::ko);
    BOOST_REQUIRE(!instance);
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_sentence__mixed_sentence__invalid)
{
    const electrum_v1 instance(join(mixed_words12), language::none);
    BOOST_REQUIRE(!instance);
}

// construct words

BOOST_AUTO_TEST_CASE(electrum_v1__construct_words__empty__invalid)
{
    BOOST_REQUIRE(!electrum_v1(string_list{}));
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_words__2_words__invalid)
{
    electrum_v1 instance(words2);
    BOOST_REQUIRE(!instance);
    BOOST_REQUIRE(instance.words().empty());
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_words__12_words__valid_expected)
{
    electrum_v1 instance(words12);
    BOOST_REQUIRE(instance);
    BOOST_REQUIRE_EQUAL(instance.words(), words12);
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_words__24_words__valid_expected)
{
    electrum_v1 instance(words24);
    BOOST_REQUIRE(instance);
    BOOST_REQUIRE_EQUAL(instance.words(), words24);
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_words__26_words__valid_expected)
{
    electrum_v1 instance(words26);
    BOOST_REQUIRE(!instance);
    BOOST_REQUIRE(instance.words().empty());
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_words__explicit_language__valid_expected)
{
    electrum_v1 instance(words12, language::en);
    BOOST_REQUIRE(instance);
    BOOST_REQUIRE_EQUAL(instance.words(), words12);
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_words__incorrect_language__invalid)
{
    electrum_v1 instance(words24, language::pt);
    BOOST_REQUIRE(!instance);
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_words__invalid_language__invalid)
{
    electrum_v1 instance(words24, language::ko);
    BOOST_REQUIRE(!instance);
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_words__mixed_words__invalid)
{
    electrum_v1 instance(mixed_words12, language::none);
    BOOST_REQUIRE(!instance);
}

// construct entropy

BOOST_AUTO_TEST_CASE(electrum_v1__construct_entropy__empty__invalid)
{
    BOOST_REQUIRE(!electrum_v1(data_chunk{}));
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_entropy__8_bytes__invalid)
{
    const data_chunk entropy(8, 0x42);
    electrum_v1 instance(entropy);
    BOOST_REQUIRE(!instance);
    BOOST_REQUIRE(instance.entropy().empty());
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_entropy__16_bytes__valid_expected)
{
    const data_chunk entropy(16, 0x42);
    electrum_v1 instance(entropy);
    BOOST_REQUIRE(instance);
    BOOST_REQUIRE_EQUAL(instance.entropy(), entropy);
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_entropy__32_bytes__valid_expected)
{
    const data_chunk entropy(32, 0x42);
    electrum_v1 instance(entropy);
    BOOST_REQUIRE(instance);
    BOOST_REQUIRE_EQUAL(instance.entropy(), entropy);
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_entropy__64_bytes__invalid)
{
    const data_chunk entropy(64, 0x42);
    electrum_v1 instance(entropy);
    BOOST_REQUIRE(!instance);
    BOOST_REQUIRE(instance.entropy().empty());
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_entropy__explicit_language__valid_expected)
{
    const data_chunk entropy(16, 0x42);
    electrum_v1 instance(entropy, language::pt);
    BOOST_REQUIRE(instance);
    BOOST_REQUIRE_EQUAL(instance.entropy(), entropy);
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_entropy__invalid_language__invalid)
{
    const data_chunk entropy(16, 0x42);
    electrum_v1 instance(entropy, language::ko);
    BOOST_REQUIRE(!instance);
}

// construct minimum_entropy

BOOST_AUTO_TEST_CASE(electrum_v1__construct_minimum_entropy__always__valid_expected)
{
    const electrum_v1::minimum_entropy entropy{ 0x42 };
    electrum_v1 instance(entropy);
    BOOST_REQUIRE(instance);
    BOOST_REQUIRE_EQUAL(instance.entropy(), to_chunk(entropy));
}

// construct maximum_entropy

BOOST_AUTO_TEST_CASE(electrum_v1__construct_maximum_entropy__always__valid_expected)
{
    const electrum_v1::maximum_entropy entropy{ 0x42 };
    electrum_v1 instance(entropy);
    BOOST_REQUIRE(instance);
    BOOST_REQUIRE_EQUAL(instance.entropy(), to_chunk(entropy));
}

// construct protected entropy

BOOST_AUTO_TEST_CASE(electrum_v1__construct_protected_entropy__empty__expected)
{
    const accessor instance({}, {}, language::ja);
    BOOST_REQUIRE(!instance);
    BOOST_REQUIRE(instance.entropy().empty());
    BOOST_REQUIRE(instance.words().empty());
    BOOST_REQUIRE(instance.lingo() == language::ja);
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_protected_entropy__not_empty__expected)
{
    const data_chunk entropy(5, 0x42);
    const string_list words(5, "word");
    const accessor instance(entropy, words, language::ja);
    BOOST_REQUIRE(instance);
    BOOST_REQUIRE_EQUAL(instance.entropy(), entropy);
    BOOST_REQUIRE_EQUAL(instance.words(), words);
    BOOST_REQUIRE(instance.lingo() == language::ja);
}

// construct protected result

BOOST_AUTO_TEST_CASE(electrum_v1__construct_protected_result__todo__todo)
{
    // Also update other constructor tests to verify overflow.
    BOOST_REQUIRE(TODO_TESTS);
}

#endif // CONSTRUCTORS

#ifdef PUBLIC_METHODS

// to_public_key

BOOST_AUTO_TEST_CASE(electrum_v1__to_public_key__invalid__invalid)
{
    electrum_v1 instance;
    BOOST_REQUIRE(!instance);
    BOOST_REQUIRE(!instance.to_public_key());
}

BOOST_AUTO_TEST_CASE(electrum_v1__to_public_key__valid__default_context__valid)
{
    const electrum_v1 instance(words12);
    BOOST_REQUIRE(instance);
    BOOST_REQUIRE(instance.to_public_key());
}

BOOST_AUTO_TEST_CASE(electrum_v1__to_public_key__valid_explicit_context__valid)
{
    const electrum_v1 instance(words12);
    BOOST_REQUIRE(instance);
    BOOST_REQUIRE(instance.to_public_key(btc_mainnet_p2kh));
}

BOOST_AUTO_TEST_CASE(electrum_v1__to_public_key__todo__todo)
{
    BOOST_REQUIRE(TODO_TESTS);
}

// to_seed

BOOST_AUTO_TEST_CASE(electrum_v1__to_seed__todo__todo)
{
    BOOST_REQUIRE(TODO_TESTS);
}

// is_overflow

BOOST_AUTO_TEST_CASE(electrum_v1__is_overflow__entropy_invalid__false)
{
    const electrum_v1 instance(data_chunk{});
    BOOST_REQUIRE(!instance);
    BOOST_REQUIRE(!instance.is_overflow());
}

BOOST_AUTO_TEST_CASE(electrum_v1__is_overflow__entropy__false)
{
    const electrum_v1 instance(data_chunk(16, 0x00));
    BOOST_REQUIRE(instance);
    BOOST_REQUIRE(!instance.is_overflow());
}

BOOST_AUTO_TEST_CASE(electrum_v1__is_overflow__words_invalid__false)
{
    const electrum_v1 instance(words2);
    BOOST_REQUIRE(!instance);
    BOOST_REQUIRE(!instance.is_overflow());
}

BOOST_AUTO_TEST_CASE(electrum_v1__is_overflow__words_not_overflowed__false)
{
    const electrum_v1 instance(words12);
    BOOST_REQUIRE(instance);
    BOOST_REQUIRE(!instance.is_overflow());
}

BOOST_AUTO_TEST_CASE(electrum_v1__is_overflow__words_overflowed__true)
{
    const electrum_v1 instance(two_overflows12);
    BOOST_REQUIRE(instance);
    BOOST_REQUIRE(instance.is_overflow());
}

// overflows

BOOST_AUTO_TEST_CASE(electrum_v1__overflows__entropy_invalid__empty)
{
    const electrum_v1 instance(data_chunk{});
    BOOST_REQUIRE(!instance);
    BOOST_REQUIRE(instance.overflows().empty());
}

BOOST_AUTO_TEST_CASE(electrum_v1__overflows__entropy__empty)
{
    const electrum_v1 instance(data_chunk(32, 0x00));
    BOOST_REQUIRE(instance);
    BOOST_REQUIRE(instance.overflows().empty());
}

BOOST_AUTO_TEST_CASE(electrum_v1__is_overflow__words_invalid__empty)
{
    const electrum_v1 instance(words2);
    BOOST_REQUIRE(!instance);
    BOOST_REQUIRE(instance.overflows().empty());
}

BOOST_AUTO_TEST_CASE(electrum_v1__overflows__words_not_overflowed__expected)
{
    const electrum_v1 instance(words24);
    BOOST_REQUIRE(instance);
    BOOST_REQUIRE(!instance.is_overflow());
    const auto& overflows = instance.overflows();
    BOOST_REQUIRE_EQUAL(overflows.size(), 24u / 3u);
    BOOST_REQUIRE(!overflows[0]);
    BOOST_REQUIRE(!overflows[1]);
    BOOST_REQUIRE(!overflows[2]);
    BOOST_REQUIRE(!overflows[3]);
    BOOST_REQUIRE(!overflows[4]);
    BOOST_REQUIRE(!overflows[5]);
    BOOST_REQUIRE(!overflows[6]);
    BOOST_REQUIRE(!overflows[7]);
}

BOOST_AUTO_TEST_CASE(electrum_v1__overflows__words_overflowed__expected)
{
    const electrum_v1 instance(two_overflows12);
    BOOST_REQUIRE(instance);
    BOOST_REQUIRE(instance.is_overflow());
    const auto& overflows = instance.overflows();
    BOOST_REQUIRE_EQUAL(overflows.size(), 12u / 3u);
    BOOST_REQUIRE(!overflows[0]);
    BOOST_REQUIRE(overflows[1]);
    BOOST_REQUIRE(!overflows[2]);
    BOOST_REQUIRE(overflows[3]);
}

#endif // PUBLIC_METHODS

#ifdef OPERATORS

// All operators are implemented in the languages base class.

// assign

BOOST_AUTO_TEST_CASE(electrum_v1__assign_copy__always__expected)
{
    const electrum_v1 instance1(words12);
    electrum_v1 instance2;
    instance2 = instance1;
    BOOST_REQUIRE(instance2);
    BOOST_REQUIRE_EQUAL(instance2.words(), words12);
    BOOST_REQUIRE_EQUAL(instance2.entropy(), instance1.entropy());
    BOOST_REQUIRE(instance2.lingo() == instance1.lingo());
}

BOOST_AUTO_TEST_CASE(electrum_v1__assign_move__always__expected)
{
    electrum_v1 instance1(words12);
    electrum_v1 instance2;
    instance2 = std::move(instance1);
    BOOST_REQUIRE(instance2);
    BOOST_REQUIRE_EQUAL(instance2.words(), words12);
    BOOST_REQUIRE_EQUAL(instance2.entropy(), instance1.entropy());
    BOOST_REQUIRE(instance2.lingo() == instance1.lingo());
}

// in/equality

BOOST_AUTO_TEST_CASE(electrum_v1__equality__always__expected)
{
    const electrum_v1 instance1(words12);
    const electrum_v1 instance2(words12);
    BOOST_REQUIRE(instance1);
    BOOST_REQUIRE(instance1 == instance2);
}

BOOST_AUTO_TEST_CASE(electrum_v1__inequality_move__always__expected)
{

    const electrum_v1 instance1(words12);
    const electrum_v1 instance2(words24);
    BOOST_REQUIRE(instance1);
    BOOST_REQUIRE(instance2);
    BOOST_REQUIRE(instance1 != instance2);
}

// operator>>

BOOST_AUTO_TEST_CASE(electrum_v1__deserialize__valid__expected)
{
    std::istringstream in{ join(words12) };
    electrum_v1 instance;
    in >> instance;
    BOOST_REQUIRE(instance);
    BOOST_REQUIRE_EQUAL(instance.words(), words12);
}

BOOST_AUTO_TEST_CASE(electrum_v1__deserialize__invalid__invalid)
{
    std::istringstream in{ join(words2) };
    electrum_v1 instance;
    in >> instance;
    BOOST_REQUIRE(!instance);
}

// operator<<

BOOST_AUTO_TEST_CASE(electrum_v1__serialize__valid__expected)
{
    std::ostringstream out;
    electrum_v1 instance(words12);
    out << instance;
    BOOST_REQUIRE_EQUAL(out.str(), join(words12));
}

BOOST_AUTO_TEST_CASE(electrum_v1__serialize__invalid__invalid)
{
    std::ostringstream out;
    electrum_v1 instance;
    BOOST_REQUIRE(!instance);
    out << instance;
    BOOST_REQUIRE(out.str().empty());
}

#endif // OPERATORS

#ifdef VERIFIED_VECTORS

BOOST_AUTO_TEST_CASE(electrum_v1__construct_sentence__vectors_electrum__expected)
{
    for (const auto& vector: vectors_electrum)
    {
        const electrum_v1 instance(vector.mnemonic, vector.lingo);
        BOOST_REQUIRE(instance);
        BOOST_REQUIRE_EQUAL(instance.sentence(), vector.mnemonic);
        BOOST_REQUIRE_EQUAL(instance.entropy(), vector.entropy);
        BOOST_REQUIRE_EQUAL(instance.words(), vector.words());
        BOOST_REQUIRE(instance.lingo() == vector.lingo);
        ////BOOST_REQUIRE_EQUAL(instance.to_public_key(vector.network), vector.key);

        // Verify overflows when testing wordlists.
        BOOST_REQUIRE_EQUAL(instance.overflows(), vector.overflows());
        BOOST_REQUIRE_EQUAL(instance.is_overflow(), vector.is_overflow());
    }
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_entropy__vectors_electrum__expected)
{
    for (const auto& vector: vectors_electrum)
    {
        const electrum_v1 instance(vector.entropy, vector.lingo);
        BOOST_REQUIRE(instance);
        BOOST_REQUIRE_EQUAL(instance.entropy(), vector.entropy);
        BOOST_REQUIRE(instance.lingo() == vector.lingo);

        // Use overflow expectations when testing from entropy.
        BOOST_REQUIRE_EQUAL(instance.words(), vector.entropy_words());
        BOOST_REQUIRE_EQUAL(instance.sentence(), vector.entropy_mnemonic());
        ////BOOST_REQUIRE_EQUAL(instance.to_public_key(vector.network), vector.entropy_key());
    }
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_sentence__vectors_local__expected)
{
    for (const auto& vector: vectors_local)
    {
        const electrum_v1 instance(vector.mnemonic, vector.lingo);
        BOOST_REQUIRE(instance);
        BOOST_REQUIRE_EQUAL(instance.sentence(), vector.mnemonic);
        BOOST_REQUIRE_EQUAL(instance.entropy(), vector.entropy);
        BOOST_REQUIRE_EQUAL(instance.words(), vector.words());
        BOOST_REQUIRE(instance.lingo() == vector.lingo);
        ////BOOST_REQUIRE_EQUAL(instance.to_public_key(vector.network), vector.key);

        // Verify overflows when testing wordlists.
        BOOST_REQUIRE_EQUAL(instance.overflows(), vector.overflows());
        BOOST_REQUIRE_EQUAL(instance.is_overflow(), vector.is_overflow());
    }
}

BOOST_AUTO_TEST_CASE(electrum_v1__construct_entropy__vectors_local__expected)
{
    for (const auto& vector: vectors_local)
    {
        const electrum_v1 instance(vector.entropy, vector.lingo);
        BOOST_REQUIRE(instance);
        BOOST_REQUIRE_EQUAL(instance.entropy(), vector.entropy);
        BOOST_REQUIRE(instance.lingo() == vector.lingo);

        // Use overflow expectations when testing from entropy.
        BOOST_REQUIRE_EQUAL(instance.words(), vector.entropy_words());
        BOOST_REQUIRE_EQUAL(instance.sentence(), vector.entropy_mnemonic());
        ////BOOST_REQUIRE_EQUAL(instance.to_public_key(vector.network), vector.entropy_key());
    }
}

#endif // VERIFIED_VECTORS

BOOST_AUTO_TEST_SUITE_END()
