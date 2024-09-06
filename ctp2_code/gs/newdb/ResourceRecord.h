
/*
 * DO NOT EDIT THIS FILE!
 * It is generated automatically by ctpdb
 */

#if defined(HAVE_PRAGMA_ONCE)
#pragma once
#endif

#ifndef RESOURCE_RECORD_H__
#define RESOURCE_RECORD_H__

class ResourceRecord;

#include "CTPDatabase.h"
#include "CTPRecord.h"
class CivArchive;
class AdvanceRecord;
class GovernmentRecord;
class IconRecord;
class SoundRecord;

#define k_Num_ResourceRecord_Tokens 37

//
// m_flags0: Resource
#define k_Resource_CantTrade_Bit                 0x00000001
#define k_Resource_ProductionPercent_Bit         0x00000002
#define k_Resource_FoodPercent_Bit               0x00000004
#define k_Resource_CommercePercent_Bit           0x00000008
#define k_Resource_SciencePercent_Bit            0x00000010
#define k_Resource_EfficiencyOrCrime_Bit         0x00000020
#define k_Resource_IsBonusGood_Bit               0x00000040
#define k_Resource_IsStrategicGood_Bit           0x00000080
#define k_Resource_IsLuxuryGood_Bit              0x00000100
#define k_Resource_AddsASlave_Bit                0x00000200
#define k_Resource_GLHidden_Bit                  0x00000400
#define k_Resource_CanUpgrade_Bit                0x00000800

class ResourceRecord : public CTPRecord
{
public:
    typedef sint32 (ResourceRecord::*IntAccessor)() const;
    typedef bool   (ResourceRecord::*BoolAccessor)() const;
    typedef double (ResourceRecord::*FloatAccessor)() const ;
    typedef bool   (ResourceRecord::*BitIntAccessor)(sint32 &val) const;
    typedef bool   (ResourceRecord::*BitFloatAccessor)(double &val) const;
    typedef sint32 (ResourceRecord::*IntArrayAccessor)(sint32 index) const;
    typedef double (ResourceRecord::*FloatArrayAccessor)(sint32 index) const;

private:
    uint32 m_flags0;
    sint32            m_Gold;
    sint32            m_Food;
    sint32            m_Production;
    sint32            m_SpriteID;
    double            m_Probability;
    sint32            m_VisibleAdvance; // Index into Advance database
    sint32            m_AvailableAdvance; // Index into Advance database
    sint32            m_VanishAdvance; // Index into Advance database
    sint32            m_Sound; // Index into Sound database
    sint32            m_Icon; // Index into Icon database
    sint32          * m_GovernmentsModified; // Index into Government database
    sint32            m_numGovernmentsModified;
    double            m_ProductionPercentValue;
    double            m_FoodPercentValue;
    double            m_CommercePercentValue;
    double            m_SciencePercentValue;
    double            m_EfficiencyOrCrimeValue;
    sint32            m_HappyInc;
    sint32            m_TradeGold;
    sint32            m_TradeFood;
    sint32            m_TradeProduction;
    sint32            m_TradeScience;
    sint32            m_AddPopulation;
    sint32            m_AddSlave;
    sint32            m_EnergyHunger;
    sint32            m_ProducesEnergy;
    bool m_hasGovernmentsModified; // GovMod specific flag

public:
    ResourceRecord() { Init(); };
    ResourceRecord(CivArchive &archive) { Serialize(archive); };
    ResourceRecord(ResourceRecord const & rval) { Init(); *this = rval; }
    ~ResourceRecord();
    ResourceRecord const & operator = (ResourceRecord const & rval);

    void Init();
    void Serialize(CivArchive &archive);

    void CheckRequiredFields(DBLexer *lex);
    sint32 Parse(DBLexer *lex, sint32 numRecords);

    void ResolveDBReferences();
    void Merge(const ResourceRecord & rval);

    sint32 GetGold() const { return m_Gold; }
    sint32 GetFood() const { return m_Food; }
    sint32 GetProduction() const { return m_Production; }
    sint32 GetSpriteID() const { return m_SpriteID; }
    double GetProbability() const { return m_Probability; }
    bool GetCantTrade() const { return (m_flags0 & k_Resource_CantTrade_Bit) != 0; }
    sint32           GetVisibleAdvanceIndex() const { return m_VisibleAdvance; }
    AdvanceRecord const * GetVisibleAdvance() const;
    sint32           GetAvailableAdvanceIndex() const { return m_AvailableAdvance; }
    AdvanceRecord const * GetAvailableAdvance() const;
    sint32           GetVanishAdvanceIndex() const { return m_VanishAdvance; }
    AdvanceRecord const * GetVanishAdvance() const;
    sint32           GetSoundIndex() const { return m_Sound; }
    SoundRecord const * GetSound() const;
    sint32           GetIconIndex() const { return m_Icon; }
    IconRecord const * GetIcon() const;
    sint32 GetGovernmentsModifiedIndex(sint32 index) const;
    const GovernmentRecord * GetGovernmentsModified(sint32 index) const;
    sint32 GetNumGovernmentsModified() const { return m_numGovernmentsModified;}
    bool HasProductionPercent() const { return (m_flags0 & k_Resource_ProductionPercent_Bit) != 0; }
    bool GetProductionPercent(double & value) const
    {
        if (m_flags0 & k_Resource_ProductionPercent_Bit)
        {
            value = m_ProductionPercentValue;
        }
        return (m_flags0 & k_Resource_ProductionPercent_Bit) != 0;
    }
    bool HasFoodPercent() const { return (m_flags0 & k_Resource_FoodPercent_Bit) != 0; }
    bool GetFoodPercent(double & value) const
    {
        if (m_flags0 & k_Resource_FoodPercent_Bit)
        {
            value = m_FoodPercentValue;
        }
        return (m_flags0 & k_Resource_FoodPercent_Bit) != 0;
    }
    bool HasCommercePercent() const { return (m_flags0 & k_Resource_CommercePercent_Bit) != 0; }
    bool GetCommercePercent(double & value) const
    {
        if (m_flags0 & k_Resource_CommercePercent_Bit)
        {
            value = m_CommercePercentValue;
        }
        return (m_flags0 & k_Resource_CommercePercent_Bit) != 0;
    }
    bool HasSciencePercent() const { return (m_flags0 & k_Resource_SciencePercent_Bit) != 0; }
    bool GetSciencePercent(double & value) const
    {
        if (m_flags0 & k_Resource_SciencePercent_Bit)
        {
            value = m_SciencePercentValue;
        }
        return (m_flags0 & k_Resource_SciencePercent_Bit) != 0;
    }
    bool HasEfficiencyOrCrime() const { return (m_flags0 & k_Resource_EfficiencyOrCrime_Bit) != 0; }
    bool GetEfficiencyOrCrime(double & value) const
    {
        if (m_flags0 & k_Resource_EfficiencyOrCrime_Bit)
        {
            value = m_EfficiencyOrCrimeValue;
        }
        return (m_flags0 & k_Resource_EfficiencyOrCrime_Bit) != 0;
    }
    sint32 GetHappyInc() const { return m_HappyInc; }
    sint32 GetTradeGold() const { return m_TradeGold; }
    sint32 GetTradeFood() const { return m_TradeFood; }
    sint32 GetTradeProduction() const { return m_TradeProduction; }
    sint32 GetTradeScience() const { return m_TradeScience; }
    sint32 GetAddPopulation() const { return m_AddPopulation; }
    sint32 GetAddSlave() const { return m_AddSlave; }
    bool GetIsBonusGood() const { return (m_flags0 & k_Resource_IsBonusGood_Bit) != 0; }
    bool GetIsStrategicGood() const { return (m_flags0 & k_Resource_IsStrategicGood_Bit) != 0; }
    bool GetIsLuxuryGood() const { return (m_flags0 & k_Resource_IsLuxuryGood_Bit) != 0; }
    bool GetAddsASlave() const { return (m_flags0 & k_Resource_AddsASlave_Bit) != 0; }
    sint32 GetEnergyHunger() const { return m_EnergyHunger; }
    sint32 GetProducesEnergy() const { return m_ProducesEnergy; }
    bool GetGLHidden() const { return (m_flags0 & k_Resource_GLHidden_Bit) != 0; }
    bool GetCanUpgrade() const { return (m_flags0 & k_Resource_CanUpgrade_Bit) != 0; }
    bool GetHasGovernmentsModified() const { return m_hasGovernmentsModified; }
    sint32 GenericGetNumGovernmentsModified() const { return m_numGovernmentsModified; }
    sint32 GenericGetGovernmentsModifiedIndex(sint32 index) const { return GetGovernmentsModifiedIndex(index); }

}; /* ResourceRecord */

struct ResourceRecordAccessorInfo
{
    ResourceRecord::IntAccessor        m_intAccessor;
    ResourceRecord::BoolAccessor       m_boolAccessor;
    ResourceRecord::FloatAccessor      m_floatAccessor;
    ResourceRecord::BitIntAccessor     m_bitIntAccessor;
    ResourceRecord::BitFloatAccessor   m_bitFloatAccessor;
    ResourceRecord::IntArrayAccessor   m_intArrayAccessor;
    ResourceRecord::FloatArrayAccessor m_floatArrayAccessor;
};

extern ResourceRecordAccessorInfo      g_ResourceRecord_Accessors[];
extern CTPDatabase<ResourceRecord> *   g_theResourceDB;

extern const char * g_Resource_Tokens[];

#endif