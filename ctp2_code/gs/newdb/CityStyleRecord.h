
/*
 * DO NOT EDIT THIS FILE!
 * It is generated automatically by ctpdb
 */

#if defined(HAVE_PRAGMA_ONCE)
#pragma once
#endif

#ifndef CITYSTYLE_RECORD_H__
#define CITYSTYLE_RECORD_H__

class CityStyleRecord;

#include "CTPDatabase.h"
#include "CTPRecord.h"
class CivArchive;
class AgeCityStyleRecord;

#define k_Num_CityStyleRecord_Tokens 12

//
// m_flags0: CityStyle
#define k_CityStyle_CPIcon_Bit                   0x00000001

class CityStyleRecord : public CTPRecord
{
public:
    typedef sint32 (CityStyleRecord::*IntAccessor)() const;
    typedef bool   (CityStyleRecord::*BoolAccessor)() const;
    typedef double (CityStyleRecord::*FloatAccessor)() const ;
    typedef bool   (CityStyleRecord::*BitIntAccessor)(sint32 &val) const;
    typedef bool   (CityStyleRecord::*BitFloatAccessor)(double &val) const;
    typedef sint32 (CityStyleRecord::*IntArrayAccessor)(sint32 index) const;
    typedef double (CityStyleRecord::*FloatArrayAccessor)(sint32 index) const;

private:
    uint32 m_flags0;
    sint32          * m_AgeStyle; // Index into AgeCityStyle database
    sint32            m_numAgeStyle;
    char *            m_CPIconValue;
    sint32            m_HappyInc;
    double            m_ProductionPercent;
    double            m_FoodPercent;
    double            m_CommercePercent;
    double            m_SciencePercent;
    sint32            m_BonusGold;
    sint32            m_BonusFood;
    sint32            m_BonusProduction;
    sint32            m_BonusScience;
    bool m_hasGovernmentsModified; // GovMod specific flag

public:
    CityStyleRecord() { Init(); };
    CityStyleRecord(CivArchive &archive) { Serialize(archive); };
    CityStyleRecord(CityStyleRecord const & rval) { Init(); *this = rval; }
    ~CityStyleRecord();
    CityStyleRecord const & operator = (CityStyleRecord const & rval);

    void Init();
    void Serialize(CivArchive &archive);

    void CheckRequiredFields(DBLexer *lex);
    sint32 Parse(DBLexer *lex, sint32 numRecords);

    void ResolveDBReferences();
    void Merge(const CityStyleRecord & rval);

    sint32 GetAgeStyleIndex(sint32 index) const;
    const AgeCityStyleRecord * GetAgeStyle(sint32 index) const;
    sint32 GetNumAgeStyle() const { return m_numAgeStyle;}
    bool HasCPIcon() const { return (m_flags0 & k_CityStyle_CPIcon_Bit) != 0; }
    bool GetCPIcon(char const * & value) const
    {
        if (m_flags0 & k_CityStyle_CPIcon_Bit)
        {
            value = m_CPIconValue;
        }
        return (m_flags0 & k_CityStyle_CPIcon_Bit) != 0;
    }
    sint32 GetHappyInc() const { return m_HappyInc; }
    double GetProductionPercent() const { return m_ProductionPercent; }
    double GetFoodPercent() const { return m_FoodPercent; }
    double GetCommercePercent() const { return m_CommercePercent; }
    double GetSciencePercent() const { return m_SciencePercent; }
    sint32 GetBonusGold() const { return m_BonusGold; }
    sint32 GetBonusFood() const { return m_BonusFood; }
    sint32 GetBonusProduction() const { return m_BonusProduction; }
    sint32 GetBonusScience() const { return m_BonusScience; }
    bool GetHasGovernmentsModified() const { return m_hasGovernmentsModified; }
    sint32 GenericGetNumGovernmentsModified() const { return 0; }
    sint32 GenericGetGovernmentsModifiedIndex(sint32 index) const { return -1; }

}; /* CityStyleRecord */

struct CityStyleRecordAccessorInfo
{
    CityStyleRecord::IntAccessor        m_intAccessor;
    CityStyleRecord::BoolAccessor       m_boolAccessor;
    CityStyleRecord::FloatAccessor      m_floatAccessor;
    CityStyleRecord::BitIntAccessor     m_bitIntAccessor;
    CityStyleRecord::BitFloatAccessor   m_bitFloatAccessor;
    CityStyleRecord::IntArrayAccessor   m_intArrayAccessor;
    CityStyleRecord::FloatArrayAccessor m_floatArrayAccessor;
};

extern CityStyleRecordAccessorInfo      g_CityStyleRecord_Accessors[];
extern CTPDatabase<CityStyleRecord> *   g_theCityStyleDB;

extern const char * g_CityStyle_Tokens[];

#endif
