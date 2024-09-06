
/*
 * DO NOT EDIT THIS FILE!
 * It is generated automatically by ctpdb
 */

#if defined(HAVE_PRAGMA_ONCE)
#pragma once
#endif

#ifndef ORDER_RECORD_H__
#define ORDER_RECORD_H__

class OrderRecord;

#include "CTPDatabase.h"
#include "CTPRecord.h"
class CivArchive;
class IconRecord;
class SoundRecord;

#define k_Num_OrderRecord_Tokens 63

//
// m_flags0: Order
#define k_Order_UnitPretest_None_Bit             0x00000001
#define k_Order_UnitPretest_CanAttack_Bit        0x00000002
#define k_Order_UnitPretest_CanEntrench_Bit      0x00000004
#define k_Order_UnitPretest_CanSueFranchise_Bit  0x00000008
#define k_Order_UnitPretest_CanSue_Bit           0x00000010
#define k_Order_UnitPretest_CanCreateFranchise_Bit 0x00000020
#define k_Order_UnitPretest_CanInvestigateCity_Bit 0x00000040
#define k_Order_UnitPretest_CanBombard_Bit       0x00000080
#define k_Order_UnitPretest_CanSettle_Bit        0x00000100
#define k_Order_UnitPretest_CanStealTechnology_Bit 0x00000200
#define k_Order_UnitPretest_CanInciteRevolution_Bit 0x00000400
#define k_Order_UnitPretest_CanAssassinateRuler_Bit 0x00000800
#define k_Order_UnitPretest_CanExpel_Bit         0x00001000
#define k_Order_UnitPretest_EstablishEmbassy_Bit 0x00002000
#define k_Order_UnitPretest_ThrowParty_Bit       0x00004000
#define k_Order_UnitPretest_CanCauseUnhappiness_Bit 0x00008000
#define k_Order_UnitPretest_CanPlantNuke_Bit     0x00010000
#define k_Order_UnitPretest_CanSlaveRaid_Bit     0x00020000
#define k_Order_UnitPretest_CanEnslaveSettler_Bit 0x00040000
#define k_Order_UnitPretest_CanUndergroundRailway_Bit 0x00080000
#define k_Order_UnitPretest_CanInciteUprising_Bit 0x00100000
#define k_Order_UnitPretest_CanBioTerror_Bit     0x00200000
#define k_Order_UnitPretest_CanPlague_Bit        0x00400000
#define k_Order_UnitPretest_CanNanoInfect_Bit    0x00800000
#define k_Order_UnitPretest_CanConvertCity_Bit   0x01000000
#define k_Order_UnitPretest_CanReformCity_Bit    0x02000000
#define k_Order_UnitPretest_CanSellIndulgences_Bit 0x04000000
#define k_Order_UnitPretest_CanFaithHeal_Bit     0x08000000
#define k_Order_UnitPretest_CanSoothsay_Bit      0x10000000
#define k_Order_UnitPretest_CanCreatePark_Bit    0x20000000
#define k_Order_UnitPretest_CanPillage_Bit       0x40000000
#define k_Order_UnitPretest_CanInjoin_Bit        0x80000000
//
// m_flags1: Order
#define k_Order_UnitPretest_CanInterceptTrade_Bit 0x00000001
#define k_Order_UnitPretest_CanAdvertise_Bit     0x00000002
#define k_Order_UnitPretest_CanNukeCity_Bit      0x00000004
#define k_Order_UnitPretest_CanTransport_Bit     0x00000008
#define k_Order_UnitPretest_CanBeTransported_Bit 0x00000010
#define k_Order_UnitPretest_CanLaunch_Bit        0x00000020
#define k_Order_UnitPretest_CanTarget_Bit        0x00000040
#define k_Order_UnitPretest_NoFuelThenCrash_Bit  0x00000080
#define k_Order_UnitPretest_CanParadrop_Bit      0x00000100
#define k_Order_UnitPretest_CanAirlift_Bit       0x00000200
#define k_Order_UnitPretest_CanRebase_Bit        0x00000400
#define k_Order_UnitPretest_CanUpgrade_Bit       0x00000800
#define k_Order_UnitPretest_Invalid_Bit          0x00001000
#define k_Order_Range_Bit                        0x00002000
#define k_Order_IsTeleport_Bit                   0x00004000
#define k_Order_IsTarget_Bit                     0x00008000
#define k_Order_GLHidden_Bit                     0x00010000
//
// m_TargetPretest bit group
#define k_Order_TargetPretest_None_Bit           0x00000001
#define k_Order_TargetPretest_EnemyCity_Bit      0x00000002
#define k_Order_TargetPretest_OwnCity_Bit        0x00000004
#define k_Order_TargetPretest_EnemyArmy_Bit      0x00000008
#define k_Order_TargetPretest_EnemySpecialUnit_Bit 0x00000010
#define k_Order_TargetPretest_EnemySettler_Bit   0x00000020
#define k_Order_TargetPretest_EnemyTradeUnit_Bit 0x00000040
#define k_Order_TargetPretest_TradeRoute_Bit     0x00000080
#define k_Order_TargetPretest_TerrainImprovement_Bit 0x00000100
#define k_Order_TargetPretest_MovePosition_Bit   0x00000200
#define k_Order_TargetPretest_AttackPosition_Bit 0x00000400
#define k_Order_TargetPretest_Transport_Bit      0x00000800
#define k_Order_TargetPretest_CanRefuel_Bit      0x00001000
#define k_Order_TargetPretest_AdjacentPosition_Bit 0x00002000

class OrderRecord : public CTPRecord
{
public:
    typedef sint32 (OrderRecord::*IntAccessor)() const;
    typedef bool   (OrderRecord::*BoolAccessor)() const;
    typedef double (OrderRecord::*FloatAccessor)() const ;
    typedef bool   (OrderRecord::*BitIntAccessor)(sint32 &val) const;
    typedef bool   (OrderRecord::*BitFloatAccessor)(double &val) const;
    typedef sint32 (OrderRecord::*IntArrayAccessor)(sint32 index) const;
    typedef double (OrderRecord::*FloatArrayAccessor)(sint32 index) const;

private:
    uint32 m_flags0;
    uint32 m_flags1;
    sint32            m_Gold;
    sint32            m_Move;
    char *            m_EventName;
    sint32            m_LocalizedName;
    sint32            m_StatusText;
    uint32            m_TargetPretest;
    sint32            m_RangeValue;
    char *            m_CPIcon;
    sint32            m_DefaultIcon; // Index into Icon database
    sint32            m_ButtonLocation;
    sint32            m_Cursor;
    sint32            m_InvalidCursor;
    sint32            m_FailSound; // Index into Sound database
    sint32            m_Sound; // Index into Sound database
    bool m_hasGovernmentsModified; // GovMod specific flag

public:
    OrderRecord() { Init(); };
    OrderRecord(CivArchive &archive) { Serialize(archive); };
    OrderRecord(OrderRecord const & rval) { Init(); *this = rval; }
    ~OrderRecord();
    OrderRecord const & operator = (OrderRecord const & rval);

    void Init();
    void Serialize(CivArchive &archive);

    void CheckRequiredFields(DBLexer *lex);
    sint32 Parse(DBLexer *lex, sint32 numRecords);

    void ResolveDBReferences();
    void Merge(const OrderRecord & rval);
    sint32 ParseTargetPretestBit(DBLexer *lex);

    sint32 GetGold() const { return m_Gold; }
    sint32 GetMove() const { return m_Move; }
    char const * GetEventName() const { return m_EventName; }
    sint32 GetLocalizedName() const { return m_LocalizedName; }
    sint32 GetStatusText() const { return m_StatusText; }
    uint32           GetTargetPretest() const { return m_TargetPretest; }
    bool             GetTargetPretestNone() const { return (m_TargetPretest & k_Order_TargetPretest_None_Bit) != 0; }
    bool             GetTargetPretestEnemyCity() const { return (m_TargetPretest & k_Order_TargetPretest_EnemyCity_Bit) != 0; }
    bool             GetTargetPretestOwnCity() const { return (m_TargetPretest & k_Order_TargetPretest_OwnCity_Bit) != 0; }
    bool             GetTargetPretestEnemyArmy() const { return (m_TargetPretest & k_Order_TargetPretest_EnemyArmy_Bit) != 0; }
    bool             GetTargetPretestEnemySpecialUnit() const { return (m_TargetPretest & k_Order_TargetPretest_EnemySpecialUnit_Bit) != 0; }
    bool             GetTargetPretestEnemySettler() const { return (m_TargetPretest & k_Order_TargetPretest_EnemySettler_Bit) != 0; }
    bool             GetTargetPretestEnemyTradeUnit() const { return (m_TargetPretest & k_Order_TargetPretest_EnemyTradeUnit_Bit) != 0; }
    bool             GetTargetPretestTradeRoute() const { return (m_TargetPretest & k_Order_TargetPretest_TradeRoute_Bit) != 0; }
    bool             GetTargetPretestTerrainImprovement() const { return (m_TargetPretest & k_Order_TargetPretest_TerrainImprovement_Bit) != 0; }
    bool             GetTargetPretestMovePosition() const { return (m_TargetPretest & k_Order_TargetPretest_MovePosition_Bit) != 0; }
    bool             GetTargetPretestAttackPosition() const { return (m_TargetPretest & k_Order_TargetPretest_AttackPosition_Bit) != 0; }
    bool             GetTargetPretestTransport() const { return (m_TargetPretest & k_Order_TargetPretest_Transport_Bit) != 0; }
    bool             GetTargetPretestCanRefuel() const { return (m_TargetPretest & k_Order_TargetPretest_CanRefuel_Bit) != 0; }
    bool             GetTargetPretestAdjacentPosition() const { return (m_TargetPretest & k_Order_TargetPretest_AdjacentPosition_Bit) != 0; }
    bool GetUnitPretest_None() const { return (m_flags0 & k_Order_UnitPretest_None_Bit) != 0; }
    bool GetUnitPretest_CanAttack() const { return (m_flags0 & k_Order_UnitPretest_CanAttack_Bit) != 0; }
    bool GetUnitPretest_CanEntrench() const { return (m_flags0 & k_Order_UnitPretest_CanEntrench_Bit) != 0; }
    bool GetUnitPretest_CanSueFranchise() const { return (m_flags0 & k_Order_UnitPretest_CanSueFranchise_Bit) != 0; }
    bool GetUnitPretest_CanSue() const { return (m_flags0 & k_Order_UnitPretest_CanSue_Bit) != 0; }
    bool GetUnitPretest_CanCreateFranchise() const { return (m_flags0 & k_Order_UnitPretest_CanCreateFranchise_Bit) != 0; }
    bool GetUnitPretest_CanInvestigateCity() const { return (m_flags0 & k_Order_UnitPretest_CanInvestigateCity_Bit) != 0; }
    bool GetUnitPretest_CanBombard() const { return (m_flags0 & k_Order_UnitPretest_CanBombard_Bit) != 0; }
    bool GetUnitPretest_CanSettle() const { return (m_flags0 & k_Order_UnitPretest_CanSettle_Bit) != 0; }
    bool GetUnitPretest_CanStealTechnology() const { return (m_flags0 & k_Order_UnitPretest_CanStealTechnology_Bit) != 0; }
    bool GetUnitPretest_CanInciteRevolution() const { return (m_flags0 & k_Order_UnitPretest_CanInciteRevolution_Bit) != 0; }
    bool GetUnitPretest_CanAssassinateRuler() const { return (m_flags0 & k_Order_UnitPretest_CanAssassinateRuler_Bit) != 0; }
    bool GetUnitPretest_CanExpel() const { return (m_flags0 & k_Order_UnitPretest_CanExpel_Bit) != 0; }
    bool GetUnitPretest_EstablishEmbassy() const { return (m_flags0 & k_Order_UnitPretest_EstablishEmbassy_Bit) != 0; }
    bool GetUnitPretest_ThrowParty() const { return (m_flags0 & k_Order_UnitPretest_ThrowParty_Bit) != 0; }
    bool GetUnitPretest_CanCauseUnhappiness() const { return (m_flags0 & k_Order_UnitPretest_CanCauseUnhappiness_Bit) != 0; }
    bool GetUnitPretest_CanPlantNuke() const { return (m_flags0 & k_Order_UnitPretest_CanPlantNuke_Bit) != 0; }
    bool GetUnitPretest_CanSlaveRaid() const { return (m_flags0 & k_Order_UnitPretest_CanSlaveRaid_Bit) != 0; }
    bool GetUnitPretest_CanEnslaveSettler() const { return (m_flags0 & k_Order_UnitPretest_CanEnslaveSettler_Bit) != 0; }
    bool GetUnitPretest_CanUndergroundRailway() const { return (m_flags0 & k_Order_UnitPretest_CanUndergroundRailway_Bit) != 0; }
    bool GetUnitPretest_CanInciteUprising() const { return (m_flags0 & k_Order_UnitPretest_CanInciteUprising_Bit) != 0; }
    bool GetUnitPretest_CanBioTerror() const { return (m_flags0 & k_Order_UnitPretest_CanBioTerror_Bit) != 0; }
    bool GetUnitPretest_CanPlague() const { return (m_flags0 & k_Order_UnitPretest_CanPlague_Bit) != 0; }
    bool GetUnitPretest_CanNanoInfect() const { return (m_flags0 & k_Order_UnitPretest_CanNanoInfect_Bit) != 0; }
    bool GetUnitPretest_CanConvertCity() const { return (m_flags0 & k_Order_UnitPretest_CanConvertCity_Bit) != 0; }
    bool GetUnitPretest_CanReformCity() const { return (m_flags0 & k_Order_UnitPretest_CanReformCity_Bit) != 0; }
    bool GetUnitPretest_CanSellIndulgences() const { return (m_flags0 & k_Order_UnitPretest_CanSellIndulgences_Bit) != 0; }
    bool GetUnitPretest_CanFaithHeal() const { return (m_flags0 & k_Order_UnitPretest_CanFaithHeal_Bit) != 0; }
    bool GetUnitPretest_CanSoothsay() const { return (m_flags0 & k_Order_UnitPretest_CanSoothsay_Bit) != 0; }
    bool GetUnitPretest_CanCreatePark() const { return (m_flags0 & k_Order_UnitPretest_CanCreatePark_Bit) != 0; }
    bool GetUnitPretest_CanPillage() const { return (m_flags0 & k_Order_UnitPretest_CanPillage_Bit) != 0; }
    bool GetUnitPretest_CanInjoin() const { return (m_flags0 & k_Order_UnitPretest_CanInjoin_Bit) != 0; }
    bool GetUnitPretest_CanInterceptTrade() const { return (m_flags1 & k_Order_UnitPretest_CanInterceptTrade_Bit) != 0; }
    bool GetUnitPretest_CanAdvertise() const { return (m_flags1 & k_Order_UnitPretest_CanAdvertise_Bit) != 0; }
    bool GetUnitPretest_CanNukeCity() const { return (m_flags1 & k_Order_UnitPretest_CanNukeCity_Bit) != 0; }
    bool GetUnitPretest_CanTransport() const { return (m_flags1 & k_Order_UnitPretest_CanTransport_Bit) != 0; }
    bool GetUnitPretest_CanBeTransported() const { return (m_flags1 & k_Order_UnitPretest_CanBeTransported_Bit) != 0; }
    bool GetUnitPretest_CanLaunch() const { return (m_flags1 & k_Order_UnitPretest_CanLaunch_Bit) != 0; }
    bool GetUnitPretest_CanTarget() const { return (m_flags1 & k_Order_UnitPretest_CanTarget_Bit) != 0; }
    bool GetUnitPretest_NoFuelThenCrash() const { return (m_flags1 & k_Order_UnitPretest_NoFuelThenCrash_Bit) != 0; }
    bool GetUnitPretest_CanParadrop() const { return (m_flags1 & k_Order_UnitPretest_CanParadrop_Bit) != 0; }
    bool GetUnitPretest_CanAirlift() const { return (m_flags1 & k_Order_UnitPretest_CanAirlift_Bit) != 0; }
    bool GetUnitPretest_CanRebase() const { return (m_flags1 & k_Order_UnitPretest_CanRebase_Bit) != 0; }
    bool GetUnitPretest_CanUpgrade() const { return (m_flags1 & k_Order_UnitPretest_CanUpgrade_Bit) != 0; }
    bool GetUnitPretest_Invalid() const { return (m_flags1 & k_Order_UnitPretest_Invalid_Bit) != 0; }
    bool HasRange() const { return (m_flags1 & k_Order_Range_Bit) != 0; }
    bool GetRange(sint32 & value) const
    {
        if (m_flags1 & k_Order_Range_Bit)
        {
            value = m_RangeValue;
        }
        return (m_flags1 & k_Order_Range_Bit) != 0;
    }
    bool GetIsTeleport() const { return (m_flags1 & k_Order_IsTeleport_Bit) != 0; }
    bool GetIsTarget() const { return (m_flags1 & k_Order_IsTarget_Bit) != 0; }
    bool GetGLHidden() const { return (m_flags1 & k_Order_GLHidden_Bit) != 0; }
    char const * GetCPIcon() const { return m_CPIcon; }
    sint32           GetDefaultIconIndex() const { return m_DefaultIcon; }
    IconRecord const * GetDefaultIcon() const;
    sint32 GetButtonLocation() const { return m_ButtonLocation; }
    sint32 GetCursor() const { return m_Cursor; }
    sint32 GetInvalidCursor() const { return m_InvalidCursor; }
    sint32           GetFailSoundIndex() const { return m_FailSound; }
    SoundRecord const * GetFailSound() const;
    sint32           GetSoundIndex() const { return m_Sound; }
    SoundRecord const * GetSound() const;
    bool GetHasGovernmentsModified() const { return m_hasGovernmentsModified; }
    sint32 GenericGetNumGovernmentsModified() const { return 0; }
    sint32 GenericGetGovernmentsModifiedIndex(sint32 index) const { return -1; }

}; /* OrderRecord */

struct OrderRecordAccessorInfo
{
    OrderRecord::IntAccessor        m_intAccessor;
    OrderRecord::BoolAccessor       m_boolAccessor;
    OrderRecord::FloatAccessor      m_floatAccessor;
    OrderRecord::BitIntAccessor     m_bitIntAccessor;
    OrderRecord::BitFloatAccessor   m_bitFloatAccessor;
    OrderRecord::IntArrayAccessor   m_intArrayAccessor;
    OrderRecord::FloatArrayAccessor m_floatArrayAccessor;
};

extern OrderRecordAccessorInfo      g_OrderRecord_Accessors[];
extern CTPDatabase<OrderRecord> *   g_theOrderDB;

extern const char * g_Order_Tokens[];

#endif
