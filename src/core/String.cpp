/************************************************************
 *
 *  OTString.cpp
 *
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1

 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.

 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.9 (Darwin)

 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
 **************************************************************/

#include <opentxs/core/String.hpp>
#include <opentxs/core/Contract.hpp>
#include <opentxs/core/OTLog.hpp>
#include <opentxs/core/crypto/OTPassword.hpp>
#include <opentxs/core/Nym.hpp>
#include <opentxs/core/crypto/OTSignature.hpp>
#include <opentxs/core/util/StringUtils.hpp>

#if !(defined(_WIN32) || defined(TARGET_OS_IPHONE) || defined(ANDROID))
#include <wordexp.h>
#endif

namespace opentxs
{

std::ostream& operator<<(std::ostream& os, const String& obj)
{
    os << obj.Get();
    return os;
}

/*
 int32_t vsnprintf(char* str, size_t size, const char* format, va_list ap);

       Upon successful return, these functions return the number of characters
       printed  (not  including  the  trailing  '\0'  used  to  end  output to
       strings).  The functions snprintf() and vsnprintf() do not  write  more
       than size bytes (including the trailing '\0').  If the output was trun-
       cated due to this limit then the return value is the number of  charac-
       ters (not including the trailing '\0') which would have been written to
       the final string if enough space had been  available.  Thus,  a  return
       value  of  size  or more means that the output was truncated. (See also
       below under NOTES.)  If an output  error  is  encountered,  a  negative
       value is returned.

 -- Therefore if size was 500, and it printed 100 characters (indices 0..99),
    then it will return 100, even though the actual bytes used are 101 (indices
 0..100),
    with the null terminator stored in the 101st byte (at index 100.) size (500)
    is not <= nsize (100) so we never enter the 'if' block in vformat.

 -- vsnprintf does not write more than size bytes, INCLUDING the null
 terminator.
    So this is actually the buffer size we are giving it (not the fmt string
 size.)

 -- If output was truncated then the return value is the number of characters
 which
    WOULD have been written, IF space had been available (NOT including the null
    terminator.) So if size is 80, but the final output would have been 90 in
 length
    (without terminator--91 with terminator), then it will return 90.

 */

// static
bool String::vformat(const char* fmt, va_list* pvl, std::string& str_Output)
{
    OT_ASSERT(nullptr != fmt);
    OT_ASSERT(nullptr != pvl);

    int32_t size = 0;
    int32_t nsize = 0;
    char* buffer = nullptr;
    va_list args;

#ifdef _WIN32
    va_list args_2 = *pvl; // windows only.

    args = *pvl;
    size = _vscprintf(fmt, args) + 1;
#else
    va_copy(args, *pvl);
    size = 512;
#endif

    buffer = new char[size + 100];
    OT_ASSERT(nullptr != buffer);
    OTPassword::zeroMemory(buffer, size + 100);

#ifdef _WIN32
    nsize = vsnprintf_s(buffer, size, size, fmt, args_2);
#else
    nsize = vsnprintf(buffer, size, fmt, args);
    va_end(args);
#endif

    OT_ASSERT(nsize >= 0);

    // fail -- delete buffer and try again
    // If nsize was 1024 bytes, then that would mean that it printed 1024
    // characters,
    // even though the actual string must be 1025 in length (to have room for
    // the null
    // terminator.)
    // If size, the ACTUAL buffer, was 1024 (that is, if size <= nsize) then
    // size would
    // LACK the necessary space to store the 1025th byte containing the null
    // terminator.
    // Therefore we are forced to delete the buffer and make one that is
    // nsize+1, so that
    // it will be 1025 bytes and thus have the necessary space for the
    // terminator
    //
    if (size <= nsize) {
        size = nsize + 1;
        delete[] buffer;
        buffer = new char[size + 100];
        OT_ASSERT(nullptr != buffer);
        OTPassword::zeroMemory(buffer, size + 100);

#ifdef _WIN32
        nsize = vsnprintf_s(buffer, size, size, fmt, *pvl);
        va_end(args);
        va_end(args_2);
#else
        nsize = vsnprintf(buffer, size, fmt, *pvl);
#endif

        OT_ASSERT(nsize >= 0);
    }
    OT_ASSERT(size > nsize);

    str_Output = buffer;
    delete[] buffer;
    buffer = nullptr;
    return true;
}

// I've greped the code for strnlen, it seems like that we are not using it.
//  This is not the correct solution for strnlen being insecure on windows.
// The correct solution is to us the 'strnlen_s' function on windows.

//#ifndef __linux__
// extern "C" {
//  size_t strnlen(const char* s, size_t max)
//   {
//       register const char *p;
//       for(p = s; *p && max--; ++p);
//       return(p - s);
//   }
//}
//#endif

// TODO  Make sure I follow this advice.

/*


It is not wise to use the ANSI standard strcpy function because of the
possibility of
unchecked buffer overflows. The better strncpy function has the problem that it
does not
properly terminate the string. The following strlcpy and strlcat functions are
simple
implementations that manage the problems of their original ANSI ancestors.


*/
// #include <string.h>

// TODO: Security: should change OTString to use size_t and MAX_SIZE instead of
// whatever it uses now. Safer.

/*
 WINDOWS:
errno_t strcpy_s(char* strDestination,
                 size_t numberOfElements,   // MAX SIZE of destination.
                 const char *strSource);

 UNIX:
 size_t strlcpy(char * restrict dst,
                const char* restrict src,
                size_t size); // MAX SIZE of destination.
*/

// static
size_t String::safe_strlen(const char* s, size_t max)
{
    OT_ASSERT_MSG(max <= MAX_STRING_LENGTH, "OT_String::safe_strlen: ASSERT: "
                                            "max length passed in is longer "
                                            "than allowed.\n");

    return strnlen(s, max);
}

// static
std::string& String::trim(std::string& str)
{
    std::string whitespaces(" \t\f\v\n\r");

    size_t found = str.find_first_not_of(whitespaces);

    if (found != std::string::npos) {
        str.erase(0, found);
    }

    found = str.find_last_not_of(whitespaces);

    if (found != std::string::npos) {
        str.erase(found + 1);
    }

    //    otErr << "(DEBUGGING OTString.cpp) CONTRACT HAS BEEN TRIMMED!!!
    // RESULT: \n\n***BEGIN TRIM DATA:%s******END TRIM DATA\n\n",
    //                  str.c_str()); // todo temp remove
    return str;
}

std::string String::replace_chars(const std::string& str,
                                  const std::string& charsFrom,
                                  const char& charTo)
{
    std::string l_str(str);
    size_t found;

    found = str.find_first_of(charsFrom);
    while (found != std::string::npos) {
        l_str[found] = charTo;
        found = str.find_first_of(charsFrom, found + 1);
    }
    return l_str;
}

#ifdef _WIN32

std::wstring String::s2ws(const std::string& s)
{
    int32_t len;
    int32_t slength = (int32_t)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    std::wstring r(len, L'\0');
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, &r[0], len);
    return r;
}

std::string String::ws2s(const std::wstring& s)
{
    int32_t len;
    int32_t slength = (int32_t)s.length() + 1;
    len = WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, 0, 0, 0, 0);
    std::string r(len, '\0');
    WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, &r[0], len, 0, 0);
    return r;
}

#endif

// ------ I cannot vouch for these top four functions, I wrote them so long ago.
// ------ But they can't hurt and I don't think they're being used anyway so I
// left them in for now.

bool String::operator>(const String& s2) const
{
    if (s2.length_ == 0) {
        return (true);
    }
    if (length_ == 0) {
        return (false);
    }
    if (strcmp(data_, s2.data_) <= 0) {
        return (false);
    }
    return (true);
}

bool String::operator<(const String& s2) const
{
    if (length_ == 0) {
        return (true);
    }
    if (s2.length_ == 0) {
        return (false);
    }
    if (strcmp(data_, s2.data_) >= 0) {
        return (false);
    }
    return (true);
}

bool String::operator<=(const String& s2) const
{
    if (length_ == 0) {
        return (true);
    }
    if (s2.length_ == 0) {
        return (false);
    }
    if (strcmp(data_, s2.data_) > 0) {
        return (false);
    }
    return (true);
}

bool String::operator>=(const String& s2) const
{
    if (s2.length_ == 0) {
        return (true);
    }
    if (length_ == 0) {
        return (false);
    }
    if (strcmp(data_, s2.data_) < 0) {
        return (false);
    }
    return (true);
}

// Note: UNIX-only (for now.)
//
bool String::TokenizeIntoKeyValuePairs(
    std::map<std::string, std::string>& mapOutput) const
{
#if !(defined(_WIN32) || defined(TARGET_OS_IPHONE) || defined(ANDROID))
    // fabcy-pansy parser that allows for multiple level of quotes nesting and
    // escaped quotes
    if (!Exists()) return true;

    wordexp_t exp_result;

    exp_result.we_wordc = 0;
    exp_result.we_wordv = nullptr;
    exp_result.we_offs = 0;

    if (wordexp(Get(), &exp_result, 0)) // non-zero == failure.
    {
        otErr << "OTString::TokenizeIntoKeyValuePairs: Error calling wordexp() "
                 "(to expand user-defined script args.)\nData: " << *this
              << "\n";
        //        wordfree(&exp_result);
        return false;
    }

    if ((exp_result.we_wordc > 0) && (nullptr != exp_result.we_wordv)) {
        // wordexp tokenizes by space (as well as expands, which is why I'm
        // using it.)
        // Therefore we need to iterate through the tokens, and create a single
        // string
        // with spaces between the tokens.
        //
        for (uint32_t i = 0;
             (i < (exp_result.we_wordc - 1)) &&
                 (exp_result.we_wordv[i] != nullptr) &&
                 (exp_result.we_wordv[i + 1] !=
                  nullptr); // odd man out. Only PAIRS of strings are processed!
             i += 2) {
            const std::string str_key = exp_result.we_wordv[i];
            const std::string str_val = exp_result.we_wordv[i + 1];

            otInfo << __FUNCTION__ << ":Parsed: " << str_key << " = " << str_val
                   << "\n";
            mapOutput.insert(
                std::pair<std::string, std::string>(str_key, str_val));
        }

        wordfree(&exp_result);
    }

    return true;
#else
    // simple parser that allows for one level of quotes nesting but no escaped
    // quotes
    if (!Exists()) return true;

    const char* txt = Get();
    std::string buf = txt;
    for (int32_t i = 0; txt[i] != 0;) {
        while (txt[i] == ' ') i++;
        int32_t k = i;
        int32_t k2 = i;
        if (txt[i] == '\'' || txt[i] == '"') {
            // quoted string
            char quote = txt[i++];
            k = i;
            while (txt[i] != quote && txt[i] != 0) i++;
            if (txt[i] != quote) {
                otErr << __FUNCTION__ << ": Unmatched quotes in: " << txt
                      << "\n";
                return false;
            }
            k2 = i;
            i++;
        }
        else {
            while (txt[i] != ' ' && txt[i] != 0) i++;
            k2 = i;
        }
        const std::string key = buf.substr(k, k2 - k);

        while (txt[i] == ' ') i++;
        int32_t v = i;
        int32_t v2 = i;
        if (txt[i] == '\'' || txt[i] == '"') {
            // quoted string
            char quote = txt[i++];
            v = i;
            while (txt[i] != quote && txt[i] != 0) i++;
            if (txt[i] != quote) {
                otErr << __FUNCTION__ << ": Unmatched quotes in: " << txt
                      << "\n";
                return false;
            }
            v2 = i;
            i++;
        }
        else {
            while (txt[i] != ' ' && txt[i] != 0) i++;
            v2 = i;
        }
        const std::string value = buf.substr(v, v2 - v);

        if (key.length() != 0 && value.length() != 0) {
            otInfo << __FUNCTION__ << ":Parsed: " << key << " = " << value
                   << "\n";
            mapOutput.insert(std::pair<std::string, std::string>(key, value));
        }
    }
    return true;
#endif
}

// static
uint64_t String::StringToUlong(const std::string& strNumber)
{
    if (strNumber.size() == 0) return 0;

    uint64_t v = 0;
    size_t i = 0;

    for (; i < strNumber.size(); ++i) {
        if (strNumber[i] < '0' || strNumber[i] > '9') break;
        v = ((v * 10) + (strNumber[i] - '0'));
    }
    return ((0 == v) ? 0 : v);
}

// static
int64_t String::StringToLong(const std::string& strNumber)
{
    if (strNumber.size() == 0) return 0;

    int64_t v = 0;
    size_t i = 0;

    char sign = (strNumber[0] == '-' || strNumber[0] == '+')
                    ? (++i, strNumber[0])
                    : '+';

    for (; i < strNumber.size(); ++i) {
        if (strNumber[i] < '0' || strNumber[i] > '9') break;
        v = ((v * 10) + (strNumber[i] - '0'));
    }
    return ((0 == v) ? 0 : ((sign == '-') ? -v : v));
}

uint64_t String::ToUlong() const
{
    const std::string str_number(Get());

    return String::StringToUlong(str_number);
}

int64_t String::ToLong() const
{
    const std::string str_number(Get());

    return String::StringToLong(str_number);
}

/*
 int64_t OTString::StringToLong(const std::string& strNumber)
 {
    char* end;
    int64_t lNumber = strtol(strNumber.c_str(), &end, 10);

    if (!*end) return lNumber;
    else
    {
        otErr << "Conversion error (str to int64_t), non-convertible part:
 %s",end);
        OT_FAIL;
        return -1;
    }
 }
 */
//
/*
 WCHAR szPassword[MAX_PATH];

 // Retrieve the password
 if (GetPasswordFromUser(szPassword, MAX_PATH))

 UsePassword(szPassword); // <===========

 // WINDOWS MEMORY ZEROING CODE:
 SecureZeroMemory(szPassword, sizeof(szPassword));


 // NEED to get linux / etc versions as well, and use them in OTString
 // as well as anywhere that std::string is used! Todo security!
 // Can probably write a custom deallocator for the std::string and then
 // zero it out similarly.
 */

void String::zeroMemory() const
{
    if (nullptr != data_) {
        OTPassword::zeroMemory(data_, length_);
    }
}

void String::Release_String(void)
{
    if (nullptr != data_) {
        // for security purposes.
        //
        OTPassword::zeroMemory(data_, length_);
        //        memset(data_, 0, length_);
        delete[] data_;
    }
    data_ = nullptr;
    position_ = 0;
    length_ = 0;
}

void String::Release(void)
{
    Release_String();

    // no need to use ot_super here, since OTString is a "base class."
}

// ***** Construction -- Destruction *****

String::~String()
{
    Release_String();
}

void String::Initialize()
{
    length_ = 0;
    position_ = 0;
    data_ = nullptr;
}

String::String()
    : length_(0)
    , position_(0)
    , data_(nullptr)
{
    //    Initialize();
}

// This constructor gets the string version of the ID passed in,
// and sets that string on this object. (For when you need a string
// version of an ID.)
String::String(const Identifier& theValue)
    : length_(0)
    , position_(0)
    , data_(nullptr)
{
    //    Initialize();

    if (theValue.GetSize() > 0) theValue.GetString(*this);
}

String::String(const Contract& theValue)
    : length_(0)
    , position_(0)
    , data_(nullptr)
{
    //    Initialize();

    (const_cast<Contract&>(theValue)).SaveContractRaw(*this);
}

// This version base64-DECODES the ascii-armored string passed in,
// and then sets the decoded plaintext string onto this object.
String::String(const OTASCIIArmor& strValue)
    : length_(0)
    , position_(0)
    , data_(nullptr)
{
    //    Initialize();

    if (strValue.Exists()) strValue.GetString(*this);
}

// This version base64-DECODES the ascii-armored signature that's passed in,
// and then sets the decoded plaintext signature onto this object.
// You would only do this when the signature, decoded, is normally in ASII
// form. Actually, that is regularly NOT the case--signatures are usually in
// binary form.
// But Lucre signatures, as used in this library, ARE in text form, so I
// provided this constructor to easily base64-decode them to prepare for
// loading into a bio and then a Lucre object.
String::String(const OTSignature& strValue)
    : length_(0)
    , position_(0)
    , data_(nullptr)
{
    //    Initialize();

    if (strValue.Exists()) strValue.GetString(*this);
}

String::String(Nym& theValue)
    : length_(0)
    , position_(0)
    , data_(nullptr)
{
    //    Initialize();

    theValue.SavePseudonym(*this);
}

String::String(const String& strValue)
    : length_(0)
    , position_(0)
    , data_(nullptr)
{
    //    Initialize();
    LowLevelSetStr(strValue);
}

String::String(const char* new_string)
    : length_(0)
    , position_(0)
    , data_(nullptr)
{
    //    Initialize();
    LowLevelSet(new_string, 0);
}

String::String(const char* new_string, size_t sizeLength)
    : length_(0)
    , position_(0)
    , data_(nullptr)
{
    //    Initialize();
    LowLevelSet(new_string, static_cast<uint32_t>(sizeLength));
}

String::String(const std::string& new_string)
    : length_(0)
    , position_(0)
    , data_(nullptr)
{
    //    Initialize();
    LowLevelSet(new_string.c_str(), static_cast<uint32_t>(new_string.length()));
}

void String::LowLevelSetStr(const String& strBuf)
{
    OT_ASSERT(nullptr == data_); // otherwise memory leak.

    if (strBuf.Exists()) {
        length_ = (MAX_STRING_LENGTH > strBuf.length_)
                      ? strBuf.length_
                      : (MAX_STRING_LENGTH - 1);

        OT_ASSERT_MSG(length_ < (MAX_STRING_LENGTH - 10),
                      "ASSERT: OTString::LowLevelSetStr: Exceeded "
                      "MAX_STRING_LENGTH! (String would not have fully fit "
                      "anyway--it would have been truncated here, potentially "
                      "causing data corruption.)"); // 10 being a buffer.

        data_ = str_dup2(strBuf.data_, length_);
    }
}

// if nEnforcedMaxLength is 10, then it will actually enforce a string at 9
// length.
// That is, up through index 8 (9th byte) instead of index 9 (10th byte.) This
// is because
// we are assuming the buffer has no more room than 10 bytes, and thus index 9
// (10th byte)
// MUST be reserved for the null terminating '\0'. Therefore, if the string is
// actually 10
// bytes int64_t, necessitating an 11th byte for the null terminator, then you
// should pass 11
// here, aka OTString::GetLength()+1. That way the entire string will fit.
//
void String::LowLevelSet(const char* new_string, uint32_t nEnforcedMaxLength)
{
    OT_ASSERT(nullptr == data_); // otherwise memory leak.

    if (nullptr != new_string) {
        uint32_t nLength =
            (nEnforcedMaxLength > 0)
                ? static_cast<uint32_t>(String::safe_strlen(
                      new_string, static_cast<size_t>(nEnforcedMaxLength)))
                : static_cast<uint32_t>(String::safe_strlen(
                      new_string, static_cast<size_t>(MAX_STRING_LENGTH -
                                                      1))); // room for \0

        // don't bother allocating memory for a 0 length string.
        if (0 == nLength) return;

        OT_ASSERT_MSG(nLength < (MAX_STRING_LENGTH - 10),
                      "ASSERT: OTString::LowLevelSet: Exceeded "
                      "MAX_STRING_LENGTH! (String would not have fully fit "
                      "anyway--it would have been truncated here, potentially "
                      "causing data corruption.)"); // 10 being a buffer.

        // Add null terminator to source string JUST IN CASE...
        // Update: this is const, so we can't change it. However, the strnlen
        // above will only have
        // worked if there was a null terminator, since otherwise we would have
        // hit the above ASSERT.
        // Therefore we should be safe enough without it here...
        //
        //      new_string[nLength] = '\0';

        data_ = str_dup2(new_string, nLength);

        if (nullptr != data_)
            length_ = nLength;
        else
            length_ = 0;
    }
}

// The source is probably NOT null-terminated.
// Size must be exact (not a max.)
//
bool String::MemSet(const char* pMem, uint32_t theSize) // if theSize is 10...
{
    Release();
    // -------------------
    if ((nullptr == pMem) || (theSize < 1)) return true;

    char* str_new = new char[theSize + 1]; // then we allocate 11
    OT_ASSERT(nullptr != str_new);
    // -------------------
    OTPassword::zeroMemory(str_new, theSize + 1);

    //  void * OTPassword::safe_memcpy(void* dest,
    //                                 uint32_t dest_size,
    //                                 const
    //                                 void   * src,
    //                                 uint32_t src_length,
    //                                 bool     bZeroSource)

    OTPassword::safe_memcpy(static_cast<void*>(str_new), theSize + 1, pMem,
                            theSize);
    //    memcpy(static_cast<void*>(str_new), pMem, theSize); // then we copy 10
    // bytes

    // todo optimize: This is probably superfluous due to the zeroMemory above.
    // Then again, we might want to remove that, and then keep this.
    str_new[theSize] = '\0'; // add null-terminator. (I deliberately made this
                             // buffer 1 byte larger so I could put the 0 at the
                             // end.) Here the index[10] is the 11th byte, since
                             // we're counting from 0.

    // Calculate the length (in case there was a null terminator in the
    // middle...)
    // This way we're guaranteed to have the correct length.
    //
    uint32_t nLength = static_cast<uint32_t>(
        String::safe_strlen(str_new, static_cast<size_t>(theSize)));
    str_new[nLength] = '\0'; // This SHOULD be superfluous as well...

    length_ = nLength; // the length doesn't count the 0.
    data_ = str_new;

    return true;
}

String& String::operator=(String rhs)
{
    if (this != &rhs) // Compare addresses.
        swap(rhs);    // Only swap if they are different objects.
    return *this;
}

void String::swap(String& rhs)
{
    std::swap(length_, rhs.length_);
    std::swap(position_, rhs.position_);
    std::swap(data_, rhs.data_);
}

bool String::At(uint32_t lIndex, char& c) const
{
    if (lIndex < length_) {
        c = data_[lIndex];
        return true;
    }
    else
        return false;
}

bool String::Exists(void) const
{
    return (nullptr != data_) ? true : false;
}

uint32_t String::GetLength(void) const
{
    return length_;
}

const char* String::Get(void) const
{
    return (nullptr != data_) ? const_cast<const char*>(data_) : "";
}

// new_string MUST be at least nEnforcedMaxLength in size if nEnforcedMaxLength
// is passed in at all.
// That's because this function forces the null terminator at that length of the
// string minus 1.

void String::Set(const char* new_string, uint32_t nEnforcedMaxLength)
{
    if (new_string == data_) // Already the same string.
        return;

    Release();

    if (nullptr == new_string) return;

    LowLevelSet(new_string, nEnforcedMaxLength);
}

void String::Set(const String& strBuf)
{
    if (this == &strBuf) // Already the same string.
        return;

    Release();

    LowLevelSetStr(strBuf);
}

bool String::operator==(const String& s2) const
{
    // If they are not the same length, return false
    if (length_ != s2.length_) {
        return (false);
    }

    // At this point we know they are at least the same length.
    // Next--are they both 0? If they are both 0, return true
    if (length_ == 0 && s2.length_ == 0) {
        return (true);
    }

    // At this point we have 2 identical-length strings.
    // Now we call strcmp and convert it to true or false.
    if (strcmp(data_, s2.data_) ==
        0) { // TODO security: use a replacement for strcmp.
        return (true);
    }
    return (false);
}

// ***** Operations *****

// Compare is simple.  True if they match, False if they don't match.
bool String::Compare(const char* strCompare) const
{
    if (nullptr == data_ || nullptr == strCompare) {
        return false;
    }

    char* s1 = data_;
    char* s2 = const_cast<char*>(strCompare);

    for (; *s1 && *s2; s1++, s2++)
        if (*s1 != *s2) return false;

    if (*s1 != *s2) return false;

    return true;
}

bool String::Compare(const String& strCompare) const
{
    if (nullptr == data_ || !strCompare.Exists()) {
        return false;
    }

    char* s1 = data_;
    const char* s2 = strCompare.Get();

    for (; *s1 && *s1 != ' '; s1++, s2++)
        if (*s1 != *s2) return false;

    return true;
}

// Contains is like compare.  True if the substring is there, false if not.
// I was going to return the position but then I realized I never needed it.
// Should be easy to modify if the need arises.
bool String::Contains(const char* strCompare) const
{
    if (nullptr == data_ || nullptr == strCompare) {
        return false;
    }

    if (strstr(data_, strCompare)) return true;

    return false;
}

bool String::Contains(const String& strCompare) const
{
    if (nullptr == data_ || !strCompare.Exists()) {
        return false;
    }

    if (strstr(data_, strCompare.Get())) return true;

    return false;
}

void String::OTfgets(std::istream& ifs)
{
    std::stringbuf sb;
    ifs.get(sb); // delimiter defaults to '\n'

    if (ifs.good()) {
        const std::string str_output = sb.str();

        Set(str_output.c_str());
    }
}

void String::ConvertToUpperCase() const
{
    if (data_ == nullptr) {
        return;
    }

    for (char* s1 = data_; *s1; s1++) {
        *s1 = static_cast<char>(toupper(*s1));
    }
}

void String::Truncate(uint32_t lAt)
{
    String strTruncated;

    strTruncated.Set(Get(), lAt);

    Set(strTruncated);
}

// If this string starts with -----BEGIN OT ARMORED...
// Then this function will load it up into an OTASCIIArmor (removing
// the bookends) and then decode it back into this string. This code
// has been repeated around so I'm doing this as a refactoring exercise.
//
// Return value: true  == There is a string in here that is not armored.
//                        (Whether I actually HAD to unarmor it or not... it's
// unarmored now.)
//               false == There was some error or the string is empty.
//
bool String::DecodeIfArmored(bool bEscapedIsAllowed)
{
    if (!Exists()) return false;

    bool bArmoredAndALSOescaped = false; // "- -----BEGIN OT ARMORED"
    bool bArmoredButNOTescaped = false;  // "-----BEGIN OT ARMORED"

    if (Contains(OT_BEGIN_ARMORED_escaped)) // check this one first...
    {
        bArmoredAndALSOescaped = true;

        if (!bEscapedIsAllowed) {
            otErr << __FUNCTION__ << ": Armored and escaped value passed in, "
                                     "but escaped are forbidden here. "
                                     "(Returning.)\n";
            return false;
        }
    }
    else if (Contains(OT_BEGIN_ARMORED)) {
        bArmoredButNOTescaped = true;
    }

    const bool bArmored = (bArmoredAndALSOescaped || bArmoredButNOTescaped);

    // Whether the string is armored or not, (-----BEGIN OT ARMORED)
    // either way, we'll end up with the decoded version in this variable:
    //
    std::string str_Trim;

    if (bArmored) // it's armored, we have to decode it first.
    {
        OTASCIIArmor ascTemp;
        if (false ==
            (ascTemp.LoadFromString(
                *this, bArmoredAndALSOescaped, // if it IS escaped or not, this
                                               // variable will be true or false
                                               // to show it.
                // The below szOverride sub-string determines where the content
                // starts, when loading.
                OT_BEGIN_ARMORED))) // Default is:       "-----BEGIN"
        // We're doing this: "-----BEGIN OT ARMORED" (Should worked for
        // escaped as well, here.)
        {
            otErr << __FUNCTION__ << ": Error loading string contents from "
                                     "ascii-armored encoding. "
                                     "Contents: \n" << Get() << "\n";
            return false;
        }
        else // success loading the actual contents out of the ascii-armored
               // version.
        {
            String strTemp(ascTemp); // <=== ascii-decoded here.
            std::string str_temp(strTemp.Get(), strTemp.GetLength());
            str_Trim = String::trim(
                str_temp); // This is the std::string for the trim process.
        }
    }
    else {
        std::string str_temp(Get(), GetLength());
        str_Trim = String::trim(str_temp); // This is the std::string for the
                                           // trim process. (Wasn't armored,
                                           // so here we use it as passed in.)
    }

    // At this point, str_Trim contains the actual contents, whether they
    // were originally ascii-armored OR NOT. (And they are also now trimmed,
    // either way.)

    Release();

    if (str_Trim.size() > 0) Set(str_Trim.c_str());

    return Exists();
}

/*
 char *str_dup2(const char* str, int32_t length)
 {
     char *str_new;
     str_new = new char [length + 1];
     strncpy(str_new, str, length);
     str_new[length] = 0;
     return str_new;
 }
 */

// inline bool vformat(const char* fmt, va_list vl, std::string& str_output)
//{
//    int32_t size      = 512;
//    char * buffer = new char[size];
//    buffer[0]     = '\0';
//
//    int32_t nsize = vsnprintf(buffer,size,fmt,vl);
//
//    //fail -- delete buffer and try again
//    if(size <= nsize)
//    {
//        delete buffer; buffer = nullptr;
//        buffer = new char[nsize+1]; //+1 for /0
//        nsize = vsnprintf(buffer,nsize,fmt,vl);
//    }
//
//    str_output = buffer;
//    delete buffer;
//    return true;
//}

void String::Format(const char* fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);

    std::string str_output;

    const bool bSuccess = String::vformat(fmt, &vl, str_output);

    va_end(vl);

    if (bSuccess) Set(str_output.c_str());
}

// append a string at the end of the current buffer.
void String::Concatenate(const char* fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);

    std::string str_output;

    const bool bSuccess = String::vformat(fmt, &vl, str_output);

    va_end(vl);

    if (bSuccess) {
        const String strConcat(str_output);

        Concatenate(strConcat);
    }
}

// append a string at the end of the current buffer.
void String::Concatenate(const String& strBuf)
{
    std::string str_output;

    if ((length_ > 0) && (nullptr != data_)) str_output += data_;

    if (strBuf.Exists() && (strBuf.GetLength() > 0)) str_output += strBuf.Get();

    Set(str_output.c_str());
}

void String::WriteToFile(std::ostream& ofs) const
{
    if (!data_) {
        return;
    }
    char* pchar = const_cast<char*>(data_);
    while (*pchar) {
        if (*pchar != '\r') ofs << *pchar;
        pchar++;
    }
}

// true  == there are more lines to read.
// false == this is the last line. Like EOF.
//
bool String::sgets(char* szBuffer, uint32_t nBufSize)
{
    if (nullptr == szBuffer) {
        return false;
    }

    if (position_ >= length_) return false;

    uint32_t lIndex = 0;
    char* pChar = data_ + position_;

    // while *pChar isn't at the end of the source string,
    // and lIndex hasn't reached the end of the destination buffer,
    //
    while (0 != *pChar && (position_ < length_) &&
           lIndex < (nBufSize - 1)) // the -1 leaves room for a forced null
                                    // terminator.
    {
        // If the current character isn't a newline, then copy it...
        if ('\n' != *pChar) {
            szBuffer[lIndex] = *pChar;
            lIndex++;    // increment the buffer
            position_++; // increment the string's internal memory of where it
                         // stopped.
            pChar++;     // increment this for convenience (could calcuate from
                         // position)
        }
        // Until we reach a newline...
        else {
            // IT'S A NEWLINE!

            szBuffer[lIndex] =
                0; // destination buffer, this is the end of the line for him.
            position_++; // This still moves past the newline, so the next
                         // call will get the next
                         // string.
            // lIndex does NOT increment here because we reach the end of this
            // string.
            // neither does pChar. These local variables go away since we are
            // returning.

            if (0 == *(pChar + 1))
                return false;
            else
                return true; // there was more to read, but we stopped at the
                             // newline.
        }
    }

    // Need to add the nullptr terminator.
    szBuffer[lIndex] = 0;

    // We reached the end of the string.
    // EOF. So we return false to tell the caller not to bother calling again.
    if (0 == *pChar) {
        return false;
    }

    // Obviously if *pChar isn't at the end, then there was more to read,
    // but the buffer was full, so we return true.
    return true;
}

char String::sgetc(void)
{
    char answer;

    if (position_ >= length_) {
        return EOF;
    }
    answer = *(data_ + position_);

    ++position_;

    return answer;
}

void String::sungetc(void)
{
    if (position_ > 0) {
        --position_;
    }
}

void String::reset(void)
{
    position_ = 0;
}

} // namespace opentxs
