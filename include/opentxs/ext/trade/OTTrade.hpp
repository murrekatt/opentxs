/************************************************************
 *
 *  OTTrade.hpp
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

// An OTTrade is derived from OTCronItem. OTCron has a list of items,
// which may be trades or agreements or who knows what next.

#ifndef OPENTXS_CORE_TRADE_OTTRADE_HPP
#define OPENTXS_CORE_TRADE_OTTRADE_HPP

#include "OTMarket.hpp"
#include "OTOffer.hpp"
#include "../cron/OTCronItem.hpp"

namespace opentxs
{

class OTIdentifier;
class OTPseudonym;

/*
 OTTrade

 Standing Order (for Trades) MUST STORE:

 X 1) Transaction ID // It took a transaction number to create this trade. We
 record it here and use it to uniquely identify the trade, like any other
 transaction.
 X 4) CURRENCY TYPE ID  (Currency type ID of whatever I’m trying to buy or sell
 WITH. Dollars? Euro?)
 X 5) Account ID SENDER (for above currency type. This is the account where I
 make my payments from, to satisfy the trades.)
 X 6) Valid date range. (Start. Expressed as an absolute date.)
 X 7) Valid date range. ( End. Expressed as an absolute date.)

 X 2) Creation date.
 X 3) INTEGER: Number of trades that have processed through this order.

 X 8) STOP ORDER — SIGN (nullptr if not a stop order — otherwise GREATER THAN or
 LESS THAN…)
 X 9) STOP ORDER — PRICE (…AT X PRICE, POST THE OFFER TO THE MARKET.)

 Cron for these orders must check expiration dates and stop order prices.

 ———————————————————————————————
 */

class OTTrade : public OTCronItem
{
private:
    typedef OTCronItem ot_super;

    OTIdentifier currencyTypeID_; // GOLD (Asset) is trading for DOLLARS
                                  // (Currency).
    OTIdentifier currencyAcctID_; // My Dollar account, used for paying for
                                  // my Gold (say) trades.

    OTOffer* offer_; // The pointer to the Offer (NOT responsible for cleaning
                     // this up!!!
    // The offer is owned by the market and I only keep a pointer here for
    // convenience.

    bool hasTradeActivated_; // Has the offer yet been first added to a
                             // market?

    int64_t stopPrice_;  // The price limit that activates the STOP order.
    char stopSign_;      // Value is 0, or '<', or '>'.
    bool stopActivated_; // If the Stop Order has already activated, I need
                         // to know that.

    int32_t tradesAlreadyDone_; // How many trades have already processed
                                // through this order? We keep track.

    OTString marketOffer_; // The market offer associated with this trade.

protected:
    virtual void onFinalReceipt(OTCronItem& origCronItem,
                                const int64_t& newTransactionNumber,
                                OTPseudonym& originator, OTPseudonym* remover);
    virtual void onRemovalFromCron();

public:
    EXPORT bool VerifyOffer(OTOffer& offer) const;
    EXPORT bool IssueTrade(OTOffer& offer, char stopSign = 0,
                           int64_t stopPrice = 0);

    // The Trade always stores the original, signed version of its Offer.
    // This method allows you to grab a copy of it.
    inline bool GetOfferString(OTString& offer)
    {
        offer.Set(marketOffer_);
        if (marketOffer_.Exists()) {
            return true;
        }
        return false;
    }

    inline bool IsStopOrder() const
    {
        if ((stopSign_ == '<') || (stopSign_ == '>')) {
            return true;
        }
        return false;
    }

    inline const int64_t& GetStopPrice() const
    {
        return stopPrice_;
    }

    inline bool IsGreaterThan() const
    {
        if (stopSign_ == '>') {
            return true;
        }
        return false;
    }

    inline bool IsLessThan() const
    {
        if (stopSign_ == '<') {
            return true;
        }
        return false;
    }

    // optionally returns the offer's market ID and a pointer to the market.
    OTOffer* GetOffer(OTIdentifier* offerMarketId = nullptr,
                      OTMarket* *market = nullptr);

    inline const OTIdentifier& GetCurrencyID() const
    {
        return currencyTypeID_;
    }

    inline void SetCurrencyID(const OTIdentifier& currencyId)
    {
        currencyTypeID_ = currencyId;
    }

    inline const OTIdentifier& GetCurrencyAcctID() const
    {
        return currencyAcctID_;
    }

    inline void SetCurrencyAcctID(const OTIdentifier& currencyAcctID)
    {
        currencyAcctID_ = currencyAcctID;
    }

    inline void IncrementTradesAlreadyDone()
    {
        tradesAlreadyDone_++;
    }

    inline int32_t GetCompletedCount()
    {
        return tradesAlreadyDone_;
    }

    EXPORT int64_t GetAssetAcctClosingNum() const;
    EXPORT int64_t GetCurrencyAcctClosingNum() const;

    // Return True if should stay on OTCron's list for more processing.
    // Return False if expired or otherwise should be removed.
    virtual bool ProcessCron(); // OTCron calls this regularly, which is my
                                // chance to expire, etc.
    virtual bool CanRemoveItemFromCron(OTPseudonym& nym);

    // From OTScriptable, we override this function. OTScriptable now does fancy
    // stuff like checking to see
    // if the Nym is an agent working on behalf of a party to the contract.
    // That's how all OTScriptable-derived
    // objects work by default.  But OTAgreement (payment plan) and OTTrade do
    // it the old way: they just check to
    // see if theNym has signed *this.
    //
    virtual bool VerifyNymAsAgent(OTPseudonym& nym, OTPseudonym& signerNym,
                                  mapOfNyms* preloadedMap = nullptr) const;

    virtual bool VerifyNymAsAgentForAccount(OTPseudonym& nym,
                                            OTAccount& account) const;
    EXPORT OTTrade();
    EXPORT OTTrade(const OTIdentifier& serverId, const OTIdentifier& assetId,
                   const OTIdentifier& assetAcctId, const OTIdentifier& userId,
                   const OTIdentifier& currencyId,
                   const OTIdentifier& currencyAcctId);
    EXPORT virtual ~OTTrade();

    void InitTrade();

    void Release_Trade();
    virtual void Release();
    virtual int64_t GetClosingNumber(const OTIdentifier& acctId) const;
    // return -1 if error, 0 if nothing, and 1 if the node was processed.
    virtual int32_t ProcessXMLNode(irr::io::IrrXMLReader*& xml);

    virtual void UpdateContents(); // Before transmission or serialization, this
                                   // is where the ledger saves its contents

    virtual bool SaveContractWallet(std::ofstream& ofs) const;
};

} // namespace opentxs

#endif // OPENTXS_CORE_TRADE_OTTRADE_HPP
