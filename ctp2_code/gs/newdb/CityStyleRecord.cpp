
/*
 * DO NOT EDIT THIS FILE!
 * It is generated automatically by ctpdb
 */
#include "c3.h"
#include "CityStyleRecord.h"

#include <algorithm>
#include "BitArray.h"
#include "c3errors.h"
#include "CTPDatabase.h"
#include "DBLexer.h"
#include "DBTokens.h"
#include "StrDB.h"

#include "AgeCityStyleRecord.h"

CTPDatabase<CityStyleRecord> *g_theCityStyleDB = NULL;

void CityStyleRecord::Init()
{
    m_flags0 = 0;
    m_AgeStyle = NULL;
    m_numAgeStyle = 0;
    m_CPIconValue = NULL;
    m_HappyInc = 0;
    m_ProductionPercent = 0.000000;
    m_FoodPercent = 0.000000;
    m_CommercePercent = 0.000000;
    m_SciencePercent = 0.000000;
    m_BonusGold = 0;
    m_BonusFood = 0;
    m_BonusProduction = 0;
    m_BonusScience = 0;
    //GovMod Specific flag initialization
    m_hasGovernmentsModified = false;
}

void CityStyleRecord::Serialize(CivArchive &archive)
{
    if(archive.IsStoring()) {
        archive << m_index;
        if(m_name >= 0){
            archive << GetIDText();
        }
        else{
            archive << static_cast<MBCHAR*>(NULL);
        }
        archive << m_flags0;
        archive << m_numAgeStyle;
        archive.Store((uint8*)m_AgeStyle, m_numAgeStyle * sizeof(sint32));

        archive << m_CPIconValue;
        archive << m_HappyInc;
        archive << m_ProductionPercent;
        archive << m_FoodPercent;
        archive << m_CommercePercent;
        archive << m_SciencePercent;
        archive << m_BonusGold;
        archive << m_BonusFood;
        archive << m_BonusProduction;
        archive << m_BonusScience;
    } else {
        //GovMod Specific flag initialization
        m_hasGovernmentsModified = false;

        archive >> m_index;
        {
            MBCHAR* tmpStr = NULL;
            archive >> tmpStr;
            g_theStringDB->GetStringID(tmpStr, m_name);
            SetTextName(g_theStringDB->GetNameStr(m_name));
        }
        archive >> m_flags0;
        archive >> m_numAgeStyle;
        archive.Load((uint8*)m_AgeStyle, m_numAgeStyle * sizeof(sint32));

        m_CPIconValue = NULL;
        archive >> m_CPIconValue;

        archive >> m_HappyInc;
        archive >> m_ProductionPercent;
        archive >> m_FoodPercent;
        archive >> m_CommercePercent;
        archive >> m_SciencePercent;
        archive >> m_BonusGold;
        archive >> m_BonusFood;
        archive >> m_BonusProduction;
        archive >> m_BonusScience;
    }
}

CityStyleRecord::~CityStyleRecord()
{
    delete [] m_AgeStyle;
    delete m_CPIconValue;
}

CityStyleRecord const & CityStyleRecord::operator = (CityStyleRecord const & rval)
{
    if (this != &rval)
    {
        m_index = rval.m_index;
        m_flags0 = rval.m_flags0;
        m_hasGovernmentsModified = rval.m_hasGovernmentsModified;

        delete [] m_AgeStyle;
        m_AgeStyle = NULL;
        if (rval.m_numAgeStyle > 0)
        {
            m_AgeStyle = new sint32 [rval.m_numAgeStyle];
            std::copy(rval.m_AgeStyle, rval.m_AgeStyle + rval.m_numAgeStyle, m_AgeStyle);
        }
        m_numAgeStyle = rval.m_numAgeStyle;

        {
            delete [] m_CPIconValue;
            m_CPIconValue = new char[strlen(rval.m_CPIconValue)+1];
            strcpy(m_CPIconValue, rval.m_CPIconValue);
        }

        m_HappyInc = rval.m_HappyInc;

        m_ProductionPercent = rval.m_ProductionPercent;

        m_FoodPercent = rval.m_FoodPercent;

        m_CommercePercent = rval.m_CommercePercent;

        m_SciencePercent = rval.m_SciencePercent;

        m_BonusGold = rval.m_BonusGold;

        m_BonusFood = rval.m_BonusFood;

        m_BonusProduction = rval.m_BonusProduction;

        m_BonusScience = rval.m_BonusScience;

    }

    return *this;
}

const char *g_CityStyle_Tokens[] =
{
    "AgeStyle",
    "CPIcon",
    "CPIconValue",
    "HappyInc",
    "ProductionPercent",
    "FoodPercent",
    "CommercePercent",
    "SciencePercent",
    "BonusGold",
    "BonusFood",
    "BonusProduction",
    "BonusScience",
};

CityStyleRecordAccessorInfo g_CityStyleRecord_Accessors[] =
{
    { &CityStyleRecord::GetNumAgeStyle, NULL, NULL, NULL, NULL, &CityStyleRecord::GetAgeStyleIndex, NULL}, /* AgeStyle (array) */
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, /* CPIcon */
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL }, /* CPIcon */
    { &CityStyleRecord::GetHappyInc, NULL, NULL, NULL, NULL, NULL, NULL },
    { NULL, NULL, &CityStyleRecord::GetProductionPercent, NULL, NULL, NULL, NULL },
    { NULL, NULL, &CityStyleRecord::GetFoodPercent, NULL, NULL, NULL, NULL },
    { NULL, NULL, &CityStyleRecord::GetCommercePercent, NULL, NULL, NULL, NULL },
    { NULL, NULL, &CityStyleRecord::GetSciencePercent, NULL, NULL, NULL, NULL },
    { &CityStyleRecord::GetBonusGold, NULL, NULL, NULL, NULL, NULL, NULL },
    { &CityStyleRecord::GetBonusFood, NULL, NULL, NULL, NULL, NULL, NULL },
    { &CityStyleRecord::GetBonusProduction, NULL, NULL, NULL, NULL, NULL, NULL },
    { &CityStyleRecord::GetBonusScience, NULL, NULL, NULL, NULL, NULL, NULL },
};

#define k_Token_CityStyle_AgeStyle               ((k_Token_Custom_Base) + 0)
#define k_Token_CityStyle_CPIcon                 ((k_Token_Custom_Base) + 1)
#define k_Token_CityStyle_CPIcon_Value           ((k_Token_Custom_Base) + 2)
#define k_Token_CityStyle_HappyInc               ((k_Token_Custom_Base) + 3)
#define k_Token_CityStyle_ProductionPercent      ((k_Token_Custom_Base) + 4)
#define k_Token_CityStyle_FoodPercent            ((k_Token_Custom_Base) + 5)
#define k_Token_CityStyle_CommercePercent        ((k_Token_Custom_Base) + 6)
#define k_Token_CityStyle_SciencePercent         ((k_Token_Custom_Base) + 7)
#define k_Token_CityStyle_BonusGold              ((k_Token_Custom_Base) + 8)
#define k_Token_CityStyle_BonusFood              ((k_Token_Custom_Base) + 9)
#define k_Token_CityStyle_BonusProduction        ((k_Token_Custom_Base) + 10)
#define k_Token_CityStyle_BonusScience           ((k_Token_Custom_Base) + 11)
#define k_Token_CityStyle_Max                    ((k_Token_Custom_Base) + 12)


static BitArray s_ParsedTokens(12);
void CityStyleRecord::CheckRequiredFields(DBLexer *lex)
{
}

sint32 CityStyleRecord::Parse(DBLexer *lex, sint32 numRecords)
{
    bool done = false;
    sint32 result = 0;
    sint32 tok;
    s_ParsedTokens.Clear();
    lex->SetTokens(g_CityStyle_Tokens, k_Token_CityStyle_Max);
    tok = lex->GetToken();
    if(tok == k_Token_Int) {
        tok = lex->GetToken(); // Accept number to make new db compatible with the old database format
    }
    if(tok != k_Token_Name) {
        char newName[256];
        sprintf(newName, "CITYSTYLE_%i", numRecords);
        if(!g_theStringDB->GetStringID(newName, m_name)) {
            g_theStringDB->InsertStr(newName, newName);
            if(!g_theStringDB->GetStringID(newName, m_name))
                SetTextName(newName);
        }
    }
    else{
        if(!g_theStringDB->GetStringID(lex->GetTokenText(), m_name)) {
            g_theStringDB->InsertStr(lex->GetTokenText(), lex->GetTokenText());
            if(!g_theStringDB->GetStringID(lex->GetTokenText(), m_name))
                SetTextName(lex->GetTokenText());
        }
        tok = lex->GetToken();
    }


    if(tok != k_Token_OpenBrace) {
        DBERROR(("Missing open brace"));
        return 0;
    }

    while(!done) {
        tok = lex->GetToken();
        if(tok >= k_Token_Custom_Base && tok < k_Token_CityStyle_Max) {
            s_ParsedTokens.SetBit(tok - k_Token_Custom_Base);
        }
        switch(tok) {
            case k_Token_CityStyle_AgeStyle:
                if(!g_theAgeCityStyleDB->ParseRecordInArray(lex, (sint32 **)&m_AgeStyle, &m_numAgeStyle))
                {
                    done = true; break;
                }
                break;
            case k_Token_CityStyle_CPIcon:
                m_flags0 |= k_CityStyle_CPIcon_Bit;
                if(!lex->GetFileAssignment(m_CPIconValue)) {
                    DBERROR(("Expected string"));
                    done = true; break;
                }
                break;
            case k_Token_CityStyle_HappyInc:
                if(!lex->GetIntAssignment(m_HappyInc)) {
                    DBERROR(("Expected integer"));
                    done = true; break;
                }
                break;
            case k_Token_CityStyle_ProductionPercent:
                if(!lex->GetFloatAssignment(m_ProductionPercent)) {
                    DBERROR(("Expected number"));
                    done = true; break;
                }
                break;
            case k_Token_CityStyle_FoodPercent:
                if(!lex->GetFloatAssignment(m_FoodPercent)) {
                    DBERROR(("Expected number"));
                    done = true; break;
                }
                break;
            case k_Token_CityStyle_CommercePercent:
                if(!lex->GetFloatAssignment(m_CommercePercent)) {
                    DBERROR(("Expected number"));
                    done = true; break;
                }
                break;
            case k_Token_CityStyle_SciencePercent:
                if(!lex->GetFloatAssignment(m_SciencePercent)) {
                    DBERROR(("Expected number"));
                    done = true; break;
                }
                break;
            case k_Token_CityStyle_BonusGold:
                if(!lex->GetIntAssignment(m_BonusGold)) {
                    DBERROR(("Expected integer"));
                    done = true; break;
                }
                break;
            case k_Token_CityStyle_BonusFood:
                if(!lex->GetIntAssignment(m_BonusFood)) {
                    DBERROR(("Expected integer"));
                    done = true; break;
                }
                break;
            case k_Token_CityStyle_BonusProduction:
                if(!lex->GetIntAssignment(m_BonusProduction)) {
                    DBERROR(("Expected integer"));
                    done = true; break;
                }
                break;
            case k_Token_CityStyle_BonusScience:
                if(!lex->GetIntAssignment(m_BonusScience)) {
                    DBERROR(("Expected integer"));
                    done = true; break;
                }
                break;
            case k_Token_CloseBrace:
                done = true;
                result = 1;
                break;
            default:
                Assert(false)
                if(!g_theAgeCityStyleDB->ParseRecordInArray(lex, &m_AgeStyle, &m_numAgeStyle)) {
                    DBERROR(("Unknown token"));
                    done = true; break;
                }
                break;
        }
    }
    CheckRequiredFields(lex);
    lex->RestoreTokens();
    return result;
}

void CityStyleRecord::ResolveDBReferences()
{
    {
        sint32 i;
        for(i = 0; i < m_numAgeStyle; i++) {
            if(m_AgeStyle[i] & 0x80000000) {
                sint32 id = m_AgeStyle[i] & 0x7fffffff;
                if(!g_theAgeCityStyleDB->GetNamedItem(id, m_AgeStyle[i])) {
                    c3errors_ErrorDialog("DB", "%s not found in AgeCityStyle database", g_theStringDB->GetNameStr(id));
                }
            } else if(m_AgeStyle[i] == 0x7fffffff){
                m_AgeStyle[i] = -1;
            }
        }
    }
}

void CityStyleRecord::Merge(const CityStyleRecord & rval){
    // resize m_AgeStyle if necessary
    if (rval.m_numAgeStyle > m_numAgeStyle)
    {
        delete [] m_AgeStyle;
        m_AgeStyle = NULL;
        if (rval.m_numAgeStyle > 0)
            m_AgeStyle = new sint32 [rval.m_numAgeStyle];
        m_numAgeStyle = rval.m_numAgeStyle;
    }
    if (rval.m_numAgeStyle > 0)
        std::copy(rval.m_AgeStyle, rval.m_AgeStyle + rval.m_numAgeStyle, m_AgeStyle);

    // only replace values that have been set
    if (rval.m_flags0 & k_CityStyle_CPIcon_Bit)
    {
        delete m_CPIconValue;
        m_CPIconValue = new char[strlen(rval.m_CPIconValue)+1];
        strcpy(m_CPIconValue, rval.m_CPIconValue);
    }

}

sint32 CityStyleRecord::GetAgeStyleIndex(sint32 index) const
{
    Assert(index >= 0);
    Assert(index < m_numAgeStyle);
    if((index < 0) || (index >= m_numAgeStyle)) {
        return 0;
    }
    return m_AgeStyle[index];
}

AgeCityStyleRecord const * CityStyleRecord::GetAgeStyle(sint32 index) const
{
    Assert(index >= 0);
    Assert(index < m_numAgeStyle);
    if((index < 0) || (index >= m_numAgeStyle)) {
        return 0;
    }
    return g_theAgeCityStyleDB->Get(m_AgeStyle[index]);
}

