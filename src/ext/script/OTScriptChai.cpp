/************************************************************
 *
 *  OTScriptChai.cpp
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

#include "script/OTParty.hpp"
#include "script/OTPartyAccount.hpp"
#include "script/OTVariable.hpp"

#ifdef OT_USE_SCRIPT_CHAI
#include "script/OTScriptChai.hpp"
#include <chaiscript/chaiscript.hpp>
#ifdef OT_USE_CHAI_STDLIB
#include <chaiscript/chaiscript_stdlib.hpp>
#endif

#include "../core/OTLog.hpp"

namespace opentxs
{

bool OTScriptChai::ExecuteScript(OTVariable* pReturnVar)
{
    using namespace chaiscript;

    OT_ASSERT(nullptr != chai);

    if (m_str_script.size() > 0) {

        /*
        chai->add(user_type<OTParty>(), "OTParty");
        chai->add(constructor<OTParty()>(), "OTParty");
        chai->add(constructor<OTParty(const OTParty&)>(), "OTParty");
        chai->add(fun<OTParty&(OTParty::*)(const
        OTParty&)>(&OTParty::operator=), "=");

        chai->add(fun(&OTParty::GetPartyName), "GetPartyName");
        chai->add(fun(&OTParty::GetNymID), "GetNymID");
        chai->add(fun(&OTParty::GetEntityID), "GetEntityID");
        chai->add(fun(&OTParty::GetPartyID), "GetPartyID");
        chai->add(fun(&OTParty::HasActiveAgent), "HasActiveAgent");
        */

        // etc

        //      chai->add(m); // Here we add the OTParty class to the
        // chaiscript engine.

        for (auto& it : m_mapParties) {
            OTParty* pParty = it.second;
            OT_ASSERT(nullptr != pParty);

            std::string party_name = pParty->GetPartyName();

            //          std::cerr << " TESTING PARTY: " << party_name <<
            // std::endl;
            //          chai->add(chaiscript::var(&d), "d");

            // Currently I don't make the entire party available -- just his ID.
            //
            // Update: The client side uses constant variables only (a block or
            // two down
            // from here) and it stores the user's ID, and acct IDs, directly in
            // those
            // variables based on name.  Whereas the server side passes in
            // Parties and
            // PartyAccounts, and only the names are made available inside the
            // scripts.
            // This way the scripts must entirely rely on the server-side API,
            // functions
            // such as move_funds(from_name, to_name), which expect a name, and
            // translate
            // only internally to resolve the ID.
            // (Contrast this with client-side scripts, which actually have the
            // real ID
            // available inside the script, and which can call any OT API
            // function that
            // exists...)
            //
            chai->add_global_const(const_var(party_name),
                                   party_name.c_str()); // Why name and not
                                                        // ID? See comment
                                                        // just above.
        }

        for (auto& it : m_mapAccounts) {
            OTPartyAccount* pAcct = it.second;
            OT_ASSERT(nullptr != pAcct);

            std::string acct_name = pAcct->GetName().Get();

            //          std::cerr << " TESTING ACCOUNT: " << acct_name <<
            // std::endl;
            //          chai->add(chaiscript::var(&d), "d");

            // Currently I don't make the entire account available -- just his
            // ID.
            //
            chai->add_global_const(const_var(acct_name),
                                   acct_name.c_str()); // See comment in
                                                       // above block for
                                                       // party name.
        }

        /*
         enum OTVariable_Access
         {
             Var_Constant,        // Constant -- you cannot change this value.
             Var_Persistent,    // Persistent -- changing value doesn't require
         notice to parties.
             Var_Important,        // Important -- changing value requires
         notice to parties.
             Var_Error_Access    // should never happen.
         };

         OTVariable_Access      GetAccess() const { return m_Access; }

         int64_t& GetValueLong() { return m_lValue; }
         bool& GetValueBool() { return m_bValue; }
         std::string& GetValueString() { return m_str_Value; }
         */

        for (auto& it : m_mapVariables) {
            const std::string var_name = it.first;
            OTVariable* pVar = it.second;
            OT_ASSERT((nullptr != pVar) && (var_name.size() > 0));

            switch (pVar->GetType()) {
            case OTVariable::Var_Integer: {
                int32_t& nValue = pVar->GetValueInteger();

                if (OTVariable::Var_Constant ==
                    pVar->GetAccess()) // no pointer here, since it's constant.
                    chai->add_global_const(const_var(pVar->CopyValueInteger()),
                                           var_name.c_str());
                else
                    chai->add(var(&nValue), // passing ptr here so the
                                            // script can modify this
                                            // variable if it wants.
                              var_name.c_str());
            } break;

            case OTVariable::Var_Bool: {
                bool& bValue = pVar->GetValueBool();

                if (OTVariable::Var_Constant ==
                    pVar->GetAccess()) // no pointer here, since it's constant.
                    chai->add_global_const(const_var(pVar->CopyValueBool()),
                                           var_name.c_str());
                else
                    chai->add(var(&bValue), // passing ptr here so the
                                            // script can modify this
                                            // variable if it wants.
                              var_name.c_str());
            } break;

            case OTVariable::Var_String: {
                std::string& str_Value = pVar->GetValueString();

                if (OTVariable::Var_Constant ==
                    pVar->GetAccess()) // no pointer here, since it's constant.
                {
                    chai->add_global_const(const_var(pVar->CopyValueString()),
                                           var_name.c_str());

                    //                      otErr << "\n\n\nOTSCRIPT DEBUGGING
                    // (const var added to script): %s\n\n\n",
                    // str_Value.c_str());
                }
                else {
                    chai->add(var(&str_Value), // passing ptr here so the
                                               // script can modify this
                                               // variable if it wants.
                              var_name.c_str());

                    //                      otErr << "\n\n\nOTSCRIPT DEBUGGING
                    // var added to script: %s \n\n\n", str_Value.c_str());
                }
            } break;

            default:
                otErr << "OTScriptChai::ExecuteScript: Failure: Unknown "
                         "variable type for variable: " << var_name << "\n";
                return false;
            }
        }

        // Here we add the mapOfParties user-defined type to the chaiscript
        // engine.
        //      chai->add(user_type<mapOfParties>(), "mapOfParties");

        // Here we add the m_mapParties member variable itself
        //      chai->add_global_const(const_var(m_mapParties),
        // "Parties");

        try {
            if (nullptr == pReturnVar) // Nothing to return.
                chai->eval(m_str_script.c_str(),
                           exception_specification<const std::exception&>(),
                           m_str_display_filename);

            else // There's a return variable.
            {
                switch (pReturnVar->GetType()) {
                case OTVariable::Var_Integer: {
                    int32_t nResult = chai->eval<int32_t>(
                        m_str_script.c_str(),
                        exception_specification<const std::exception&>(),
                        m_str_display_filename);
                    pReturnVar->SetValue(nResult);
                } break;

                case OTVariable::Var_Bool: {
                    bool bResult = chai->eval<bool>(
                        m_str_script.c_str(),
                        exception_specification<const std::exception&>(),
                        m_str_display_filename);
                    pReturnVar->SetValue(bResult);
                } break;

                case OTVariable::Var_String: {
                    std::string str_Result = chai->eval<std::string>(
                        m_str_script.c_str(),
                        exception_specification<const std::exception&>(),
                        m_str_display_filename);
                    pReturnVar->SetValue(str_Result);
                } break;

                default:
                    otErr << "OTScriptChai::ExecuteScript: Unknown return type "
                             "passed in, "
                             "unable to service it.\n";
                    return false;
                } // switch
            }     // else return variable.
        }         // try
        catch (const chaiscript::exception::eval_error& ee) {
            // Error in script parsing / execution
            otErr << "OTScriptChai::ExecuteScript: \n Caught "
                     "chaiscript::exception::eval_error: \n " << ee.reason
                  << ". \n   File: " << ee.filename
                  << "\n"
                     "   Start position, line: " << ee.start_position.line
                  << " column: " << ee.start_position.column
                  << "\n"
                     "   End position,   line: " << ee.end_position.line
                  << " column: " << ee.end_position.column << "\n\n";

            std::cout << ee.what();
            if (ee.call_stack.size() > 0) {
                std::cout << "during evaluation at ("
                          << ee.call_stack[0]->start.line << ", "
                          << ee.call_stack[0]->start.column << ")";
            }
            std::cout << std::endl;
            std::cout << std::endl;

            //          std::cout << ee.what();
            if (ee.call_stack.size() > 0) {
                //                std::cout << "during evaluation at (" <<
                // *(ee.call_stack[0]->filename) << " " <<
                // ee.call_stack[0]->start.line << ", " <<
                // ee.call_stack[0]->start.column << ")";

                //                const std::string text;
                //                boost::shared_ptr<const std::string> filename;

                for (size_t j = 1; j < ee.call_stack.size(); ++j) {
                    if (ee.call_stack[j]->identifier !=
                            chaiscript::AST_Node_Type::Block &&
                        ee.call_stack[j]->identifier !=
                            chaiscript::AST_Node_Type::File) {
                        std::cout << std::endl;
                        std::cout << "  from " << *(ee.call_stack[j]->filename)
                                  << " (" << ee.call_stack[j]->start.line
                                  << ", " << ee.call_stack[j]->start.column
                                  << ") : ";
                        std::cout << ee.call_stack[j]->text << std::endl;
                    }
                }
            }
            std::cout << std::endl;

            return false;
        }
        catch (const chaiscript::exception::bad_boxed_cast& e) {
            // Error unboxing return value
            otErr << "OTScriptChai::ExecuteScript: Caught "
                     "chaiscript::exception::bad_boxed_cast : "
                  << ((e.what() != nullptr) ? e.what()
                                            : "e.what() returned null, sorry")
                  << ".\n";
            return false;
        }
        catch (const std::exception& e) {
            // Error explicitly thrown from script
            otErr << "OTScriptChai::ExecuteScript: Caught std::exception "
                     "exception: " << ((e.what() != nullptr)
                                           ? e.what()
                                           : "e.what() returned null, sorry")
                  << "\n";
            return false;
        }
        //      catch (chaiscript::Boxed_Value bv)
        catch (...) {
            //          int32_t i = chaiscript::boxed_cast<int32_t>(bv);
            otErr << "OTScriptChai::ExecuteScript: Caught exception.\n";
            return false;
        }
    }

    return true;
}

#if !defined(OT_USE_CHAI_STDLIB)

OTScriptChai::OTScriptChai()
    : OTScript()
    , chai(new chaiscript::ChaiScript())
{
}

OTScriptChai::OTScriptChai(const OTString& strValue)
    : OTScript(strValue)
    , chai(new chaiscript::ChaiScript())
{
}

OTScriptChai::OTScriptChai(const char* new_string)
    : OTScript(new_string)
    , chai(new chaiscript::ChaiScript())
{
}

OTScriptChai::OTScriptChai(const char* new_string, size_t sizeLength)
    : OTScript(new_string, sizeLength)
    , chai(new chaiscript::ChaiScript())
{
}

OTScriptChai::OTScriptChai(const std::string& new_string)
    : OTScript(new_string)
    , chai(new chaiscript::ChaiScript())
{
}

#else

OTScriptChai::OTScriptChai()
    : OTScript()
    , chai(new chaiscript::ChaiScript(chaiscript::Std_Lib::library()))
{
}

OTScriptChai::OTScriptChai(const OTString& strValue)
    : OTScript(strValue)
    , chai(new chaiscript::ChaiScript(chaiscript::Std_Lib::library()))
{
}

OTScriptChai::OTScriptChai(const char* new_string)
    : OTScript(new_string)
    , chai(new chaiscript::ChaiScript(chaiscript::Std_Lib::library()))
{
}

OTScriptChai::OTScriptChai(const char* new_string, size_t sizeLength)
    : OTScript(new_string, sizeLength)
    , chai(new chaiscript::ChaiScript(chaiscript::Std_Lib::library()))
{
}

OTScriptChai::OTScriptChai(const std::string& new_string)
    : OTScript(new_string)
    , chai(new chaiscript::ChaiScript(chaiscript::Std_Lib::library()))
{
}

#endif // OT_USE_CHAI_STDLIB

OTScriptChai::~OTScriptChai()
{
    if (nullptr != chai) delete chai;
}

} // namespace opentxs

#endif // OT_USE_SCRIPT_CHAI
