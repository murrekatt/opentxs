/************************************************************
 *
 *  OTPartyAccount.cpp
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

#include "../core/stdafx.hpp"

#include "script/OTPartyAccount.hpp"
#include "script/OTAgent.hpp"
#include "script/OTParty.hpp"
#include "script/OTScript.hpp"
#include "../core/OTAccount.hpp"
#include "../core/OTLog.hpp"

// IDEA: Put a Nym in the Nyms folder for each entity. While it may
// not have a public key in the pubkey folder, or embedded within it,
// it can still have information about the entity or role related to it,
// which becomes accessible when that Nym is loaded based on the Entity ID.
// This also makes sure that Nyms and Entities don't ever share IDs, so the
// IDs become more and more interchangeable.

namespace opentxs
{

OTPartyAccount::OTPartyAccount()
    : m_pForParty(nullptr)
    , m_pAccount(nullptr)
    , m_lClosingTransNo(0)
{
}

// For an account to be party to an agreement, there must be a closing
// transaction #
// provided, for the finalReceipt for that account.
//
OTPartyAccount::OTPartyAccount(std::string str_account_name,
                               const OTString& strAgentName,
                               OTAccount& theAccount, int64_t lClosingTransNo)
    : m_pForParty(nullptr)
    , // This gets set when this partyaccount is added to its party.
    m_pAccount(&theAccount)
    , m_lClosingTransNo(lClosingTransNo)
    , m_strName(str_account_name.c_str())
    , m_strAcctID(theAccount.GetRealAccountID())
    , m_strAssetTypeID(theAccount.GetAssetTypeID())
    , m_strAgentName(strAgentName)
{
}

OTPartyAccount::OTPartyAccount(const OTString& strName,
                               const OTString& strAgentName,
                               const OTString& strAcctID,
                               const OTString& strAssetTypeID,
                               int64_t lClosingTransNo)
    : m_pForParty(nullptr)
    , // This gets set when this partyaccount is added to its party.
    m_pAccount(nullptr)
    , m_lClosingTransNo(lClosingTransNo)
    , m_strName(strName)
    , m_strAcctID(strAcctID)
    , m_strAssetTypeID(strAssetTypeID)
    , m_strAgentName(strAgentName)
{
}

// Every partyaccount has its own authorized agent's name.
// Use that name to look up the agent ON THE PARTY (I already
// have a pointer to my owner party.)
//
OTAgent* OTPartyAccount::GetAuthorizedAgent()
{
    OT_ASSERT(nullptr != m_pForParty);

    if (!m_strAgentName.Exists()) {
        otErr << "OTPartyAccount::GetAuthorizedAgent: Error: Authorized agent "
                 "name (for this account) is blank!\n";
        return nullptr;
    }

    const std::string str_agent_name = m_strAgentName.Get();

    OTAgent* pAgent = m_pForParty->GetAgent(str_agent_name);

    return pAgent;
}

// This happens when the partyaccount is added to the party.
//
void OTPartyAccount::SetParty(OTParty& theOwnerParty)
{
    m_pForParty = &theOwnerParty;
}

OTPartyAccount::~OTPartyAccount()
{
    // m_pForParty and m_pAccount NOT cleaned up here. pointer is only for
    // convenience.
    m_pForParty = nullptr;
    m_pAccount = nullptr;
}

bool OTPartyAccount::IsAccountByID(const OTIdentifier& theAcctID) const
{
    if (!m_strAcctID.Exists()) {
        return false;
    }

    if (!m_strAssetTypeID.Exists()) {
        return false;
    }

    const OTIdentifier theMemberAcctID(m_strAcctID);
    if (!(theAcctID == theMemberAcctID)) {
        OTString strRHS(theAcctID);
        otLog4 << "OTPartyAccount::IsAccountByID: Account IDs don't match: "
               << m_strAcctID << " / " << strRHS << " \n";
        // I set output to 4 because it's normal to call IsAccountByID() even
        // when they don't match.
        return false;
    }

    // They  match!

    return true;
}

bool OTPartyAccount::IsAccount(OTAccount& theAccount)
{
    if (!m_strAcctID.Exists()) {
        otErr << "OTPartyAccount::IsAccount: Error: Empty m_strAcctID.\n";
        return false;
    }

    if (!m_strAssetTypeID.Exists()) {
        otErr << "OTPartyAccount::IsAccount: Error: Empty m_strAssetTypeID.\n";
        return false;
    }

    const OTIdentifier theAcctID(m_strAcctID);
    if (!(theAccount.GetRealAccountID() == theAcctID)) {
        OTString strRHS(theAccount.GetRealAccountID());
        otLog4 << "OTPartyAccount::IsAccount: Account IDs don't match: "
               << m_strAcctID << " / " << strRHS
               << " \n"; // I set output to 4 because it's normal to call
                         // IsAccount() even when they don't match.
        return false;
    }

    const OTIdentifier theAssetTypeID(m_strAssetTypeID);
    if (!(theAccount.GetAssetTypeID() == theAssetTypeID)) {
        OTString strRHS(theAccount.GetAssetTypeID());
        otOut << "OTPartyAccount::IsAccount: Asset Type IDs don't match ( "
              << m_strAssetTypeID << " / " << strRHS
              << " ) for Acct ID: " << m_strAcctID << " \n";
        return false;
    }

    m_pAccount = &theAccount;
    return true;
}

// I have a ptr to my owner (party), as well as to the actual account.
// I will ask him to verify whether he actually owns it.
bool OTPartyAccount::VerifyOwnership() const
{
    if (nullptr == m_pForParty) {
        otErr << "OTPartyAccount::VerifyOwnership: Error: nullptr pointer to "
                 "owner party. \n";
        return false;
    }
    if (nullptr == m_pAccount) {
        otErr << "OTPartyAccount::VerifyOwnership: Error: nullptr pointer to "
                 "account. (This function expects account to already be "
                 "loaded.) \n";
        return false;
    } // todo maybe turn the above into OT_ASSERT()s.

    if (!m_pForParty->VerifyOwnershipOfAccount(*m_pAccount)) {
        otOut << "OTPartyAccount::VerifyOwnership: Party %s doesn't verify as "
                 "the ACTUAL owner of account: " << m_strName << " \n";
        return false;
    }

    return true;
}

// I can get a ptr to my agent, and I have one to the actual account.
// I will ask him to verify whether he actually has agency over it.
bool OTPartyAccount::VerifyAgency()
{
    if (nullptr == m_pAccount) {
        otErr << "OTPartyAccount::VerifyAgency: Error: nullptr pointer to "
                 "account. (This function expects account to already be "
                 "loaded.) \n";
        return false;
    } // todo maybe turn the above into OT_ASSERT()s.

    OTAgent* pAgent = GetAuthorizedAgent();

    if (nullptr == pAgent) {
        otOut
            << "OTPartyAccount::VerifyAgency: Unable to find authorized agent ("
            << GetAgentName() << ") for this account: " << GetName() << " \n";
        return false;
    }

    if (!pAgent->VerifyAgencyOfAccount(*m_pAccount)) {
        otOut << "OTPartyAccount::VerifyAgency: Agent " << GetAgentName()
              << " doesn't verify as ACTUALLY having rights over account "
              << GetName() << " with ID: " << GetAcctID() << " \n";
        return false;
    }

    return true;
}

bool OTPartyAccount::DropFinalReceiptToInbox(
    mapOfNyms* pNymMap, const OTString& strServerID, OTPseudonym& theServerNym,
    OTSmartContract& theSmartContract, const int64_t& lNewTransactionNumber,
    const OTString& strOrigCronItem, OTString* pstrNote,
    OTString* pstrAttachment)
{
    const char* szFunc = "OTPartyAccount::DropFinalReceiptToInbox";

    if (nullptr == m_pForParty) {
        otErr << szFunc << ": nullptr m_pForParty.\n";
        return false;
    }
    else if (!m_strAcctID.Exists()) {
        otErr << szFunc << ": Empty Acct ID.\n";
        return false;
    }
    else if (!m_strAgentName.Exists()) {
        otErr << szFunc << ": No agent named for this account.\n";
        return false;
    }

    // TODO: When entites and roles are added, this function may change a bit to
    // accommodate them.

    const std::string str_agent_name(m_strAgentName.Get());

    OTAgent* pAgent = m_pForParty->GetAgent(str_agent_name);

    if (nullptr == pAgent)
        otErr << szFunc << ": named agent wasn't found on party.\n";
    else {
        const OTIdentifier theAccountID(m_strAcctID);

        return pAgent->DropFinalReceiptToInbox(
            pNymMap, strServerID, theServerNym, theSmartContract,
            theAccountID,                             // acct ID from this.
            lNewTransactionNumber, m_lClosingTransNo, // closing_no from this.
            strOrigCronItem, pstrNote, pstrAttachment);
    }

    return false;
}

// CALLER IS RESPONSIBLE TO DELETE.
// This is very low-level. (It's better to use OTPartyAccount through it's
// interface, than to
// just load up its account directly.) But this is here because it is
// appropriate in certain cases.
//
OTAccount* OTPartyAccount::LoadAccount(OTPseudonym& theSignerNym,
                                       const OTString& strServerID)
{
    if (!m_strAcctID.Exists()) {
        otOut << "OTPartyAccount::LoadAccount: Bad: Acct ID is blank for "
                 "account: " << m_strName << " \n";
        return nullptr;
    }

    const OTIdentifier theAcctID(m_strAcctID), theServerID(strServerID);

    OTAccount* pAccount =
        OTAccount::LoadExistingAccount(theAcctID, theServerID);

    if (nullptr == pAccount) {
        otOut << "OTPartyAccount::LoadAccount: Failed trying to load account: "
              << m_strName << ", with AcctID: " << m_strAcctID << " \n";
        return nullptr;
    }
    // BELOW THIS POINT, You must delete pAccount if you don't return it!!
    //
    else if (!pAccount->VerifyAccount(theSignerNym)) {
        otOut
            << "OTPartyAccount::LoadAccount: Failed trying to verify account: "
            << m_strName << ", with AcctID: " << m_strAcctID << " \n";
        delete pAccount;
        return nullptr;
    }

    // This compares asset type ID, AND account ID on the actual loaded account,
    // to what is expected.
    else if (!IsAccount(*pAccount)) // It also sets the internal pointer
                                    // m_pAccount... FYI.
    {
        // IsAccount has plenty of logging already.
        delete pAccount;
        return nullptr;
    }
    // BELOW THIS POINT, pAccount is loaded and validated, in-and-of-itself, and
    // against the PartyAcct.
    // (But not against the party ownership and agent rights.)
    // It must be deleted or will leak.

    // (No need to set m_pAccount, as that happened already in IsAccount().)

    return pAccount;
}

void OTPartyAccount::Serialize(OTString& strAppend, bool bCalculatingID,
                               bool bSpecifyAssetID) const
{
    strAppend.Concatenate(
        "<assetAccount\n name=\"%s\"\n"
        " acctID=\"%s\"\n"
        " assetTypeID=\"%s\"\n"
        " agentName=\"%s\"\n"
        " closingTransNo=\"%lld\" />\n\n",
        m_strName.Get(), bCalculatingID ? "" : m_strAcctID.Get(),
        (bCalculatingID && !bSpecifyAssetID) ? "" : m_strAssetTypeID.Get(),
        bCalculatingID ? "" : m_strAgentName.Get(),
        bCalculatingID ? 0 : m_lClosingTransNo);
}

void OTPartyAccount::RegisterForExecution(OTScript& theScript)
{
    const std::string str_acct_name = m_strName.Get();
    theScript.AddAccount(str_acct_name, *this);
}

// Done
bool OTPartyAccount::Compare(const OTPartyAccount& rhs) const
{
    if (!(GetName().Compare(rhs.GetName()))) {
        otOut << "OTPartyAccount::Compare: Names don't match: " << GetName()
              << " / " << rhs.GetName() << " \n";
        return false;
    }

    if ((GetClosingTransNo() > 0) && (rhs.GetClosingTransNo() > 0) &&
        (GetClosingTransNo() != rhs.GetClosingTransNo())) {
        otOut << "OTPartyAccount::Compare: Closing transaction numbers don't "
                 "match: " << GetName() << " \n";
        return false;
    }

    if ((GetAcctID().Exists()) && (rhs.GetAcctID().Exists()) &&
        (!GetAcctID().Compare(rhs.GetAcctID()))) {
        otOut << "OTPartyAccount::Compare: Asset account numbers don't match "
                 "for party account " << GetName() << ".\n( " << GetAcctID()
              << "  /  " << rhs.GetAcctID() << " ) \n";
        return false;
    }

    if ((GetAgentName().Exists()) && (rhs.GetAgentName().Exists()) &&
        (!GetAgentName().Compare(rhs.GetAgentName()))) {
        otOut << "OTPartyAccount::Compare: Agent names don't match for party "
                 "account " << GetName() << ".\n( " << GetAgentName() << "  /  "
              << rhs.GetAgentName() << " ) \n";
        return false;
    }

    if (!(GetAssetTypeID().Exists()) || !(rhs.GetAssetTypeID().Exists()) ||
        !(GetAssetTypeID().Compare(rhs.GetAssetTypeID()))) {
        otOut << "OTPartyAccount::Compare: Asset Type IDs don't exist, or "
                 "don't match ( " << GetAssetTypeID() << " / "
              << rhs.GetAssetTypeID() << " ) for party's account: " << GetName()
              << " \n";
        return false;
    }

    return true;
}

} // namespace opentxs
