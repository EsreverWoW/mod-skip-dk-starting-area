/*
 *MIT License
 *
 *Copyright (c) 2022 Azerothcore
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy
 *of this software and associated documentation files (the "Software"), to deal
 *in the Software without restriction, including without limitation the rights
 *to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *copies of the Software, and to permit persons to whom the Software is
 *furnished to do so, subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all
 *copies or substantial portions of the Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *SOFTWARE.
 *
 * Skip Death Knight Module
 * Original Module From Single Player Project Consolidated Skip Module
 * Rewritten for TC 335 By Single Player Project Developer MDic
 * Original Concept from conanhun513
 * Assistance and Review by JinnaiX
 * Modified for Azerothcore
 */

#include "AccountMgr.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Config.h"
#include "Common.h"
#include "Chat.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "SharedDefines.h"
#include "World.h"
#include "WorldSession.h"

class AzerothCore_skip_deathknight_announce : public PlayerScript
{
public:
    AzerothCore_skip_deathknight_announce() : PlayerScript("AzerothCore_skip_deathknight_announce") { }

    void OnLogin(Player* Player)
    {
        if (sConfigMgr->GetOption<bool>("Skip.Deathknight.Starter.Announce.enable", true) && (sConfigMgr->GetOption<bool>("Skip.Deathknight.Starter.Enable", true) || sConfigMgr->GetOption<bool>("Skip.Deathknight.Optional.Enable", true)))
        {
            ChatHandler(Player->GetSession()).SendSysMessage("This server is running the |cff4CFF00Azerothcore Skip Deathknight Starter |rmodule.");
        }
    }
};

class AzerothCore_skip_deathknight : public PlayerScript
{
public:
    AzerothCore_skip_deathknight() : PlayerScript("AzerothCore_skip_deathknight") { }

    void OnFirstLogin(Player* player)
    {
        int DKL = sConfigMgr->GetOption<float>("Skip.Deathknight.Start.Level", 58);

        if (sConfigMgr->GetOption<bool>("Skip.Deathknight.Starter.Enable", true))
        {
            if (player->GetSession()->GetSecurity() == SEC_PLAYER && player->GetAreaId() == 4342)
            {
                player->GiveLevel(DKL);
                player->learnSpell(53428);//runeforging
                player->learnSpell(53441);//runeforging
                player->learnSpell(53344);//runeforging
                player->learnSpell(62158);//runeforging
                player->learnSpell(33391);//journeyman riding
                player->learnSpell(54586);//runeforging credit
                player->learnSpell(48778);//acherus deathcharger
                player->learnSkillRewardedSpells(776, 375);//Runeforging
                player->learnSkillRewardedSpells(960, 375);//Runeforging

                if (player->GetQuestStatus(12657) == QUEST_STATUS_NONE)//The Might Of The Scourge
                {
                    player->AddQuest(sObjectMgr->GetQuestTemplate(12657), nullptr);
                    player->RewardQuest(sObjectMgr->GetQuestTemplate(12657), false, player);
                }
                if (player->GetQuestStatus(12801) == QUEST_STATUS_NONE)//The Light of Dawn
                {
                    player->AddQuest(sObjectMgr->GetQuestTemplate(12801), nullptr);
                    player->RewardQuest(sObjectMgr->GetQuestTemplate(12801), false, player);
                }
                if (player->GetTeamId() == TEAM_ALLIANCE && player->GetQuestStatus(13188) == QUEST_STATUS_NONE)//Where Kings Walk
                {
                    player->AddQuest(sObjectMgr->GetQuestTemplate(13188), nullptr);
                    player->RewardQuest(sObjectMgr->GetQuestTemplate(13188), false, player);
                }
                else if (player->GetTeamId() == TEAM_HORDE && player->GetQuestStatus(13189) == QUEST_STATUS_NONE)//Saurfang's Blessing
                {
                    player->AddQuest(sObjectMgr->GetQuestTemplate(13189), nullptr);
                    player->RewardQuest(sObjectMgr->GetQuestTemplate(13189), false, player);
                }
                player->TeleportTo(571, 5806.69f, 642.95f, 609.89f, 4.02f);//Dalaran
                ObjectAccessor::SaveAllPlayers();//Save
            }
        }

        if (sConfigMgr->GetOption<bool>("GM.Skip.Deathknight.Starter.Enable", true))
        {
            if (player->GetSession()->GetSecurity() >= SEC_MODERATOR && player->GetAreaId() == 4342)
            {
                player->GiveLevel(DKL);
                player->learnSpell(53428);//runeforging
                player->learnSpell(53441);//runeforging
                player->learnSpell(53344);//runeforging
                player->learnSpell(62158);//runeforging
                player->learnSpell(33391);//journeyman riding
                player->learnSpell(54586);//runeforging credit
                player->learnSpell(48778);//acherus deathcharger
                player->learnSkillRewardedSpells(776, 375);//Runeforging
                player->learnSkillRewardedSpells(960, 375);//Runeforging

                if (player->GetQuestStatus(12657) == QUEST_STATUS_NONE)//The Might Of The Scourge
                {
                    player->AddQuest(sObjectMgr->GetQuestTemplate(12657), nullptr);
                    player->RewardQuest(sObjectMgr->GetQuestTemplate(12657), false, player);
                }
                if (player->GetQuestStatus(12801) == QUEST_STATUS_NONE)//The Light of Dawn
                {
                    player->AddQuest(sObjectMgr->GetQuestTemplate(12801), nullptr);
                    player->RewardQuest(sObjectMgr->GetQuestTemplate(12801), false, player);
                }
                if (player->GetTeamId() == TEAM_ALLIANCE && player->GetQuestStatus(13188) == QUEST_STATUS_NONE)//Where Kings Walk
                {
                    player->AddQuest(sObjectMgr->GetQuestTemplate(13188), nullptr);
                    player->RewardQuest(sObjectMgr->GetQuestTemplate(13188), false, player);
                }
                else if (player->GetTeamId() == TEAM_HORDE && player->GetQuestStatus(13189) == QUEST_STATUS_NONE)//Saurfang's Blessing
                {
                    player->AddQuest(sObjectMgr->GetQuestTemplate(13189), nullptr);
                    player->RewardQuest(sObjectMgr->GetQuestTemplate(13189), false, player);
                }
                player->TeleportTo(571, 5806.69f, 642.95f, 609.89f, 4.02f);//Dalaran
                // mapID, x, y, z, orientation
                ObjectAccessor::SaveAllPlayers();//Save
            }
        }
    }
};

#define LOCALE_LICHKING_0 "I wish to skip the Death Knight starter questline."
#define LOCALE_LICHKING_1 "죽음의 기사 스타터 퀘스트 라인을 건너뛰고 싶습니다."
#define LOCALE_LICHKING_2 "Je souhaite sauter la série de quêtes de démarrage du Chevalier de la mort."
#define LOCALE_LICHKING_3 "Ich möchte die Todesritter-Starter-Questreihe überspringen."
#define LOCALE_LICHKING_4 "我想跳過死亡騎士新手任務線。"
#define LOCALE_LICHKING_5 "我想跳過死亡騎士新手任務線。"
#define LOCALE_LICHKING_6 "Deseo saltarme la línea de misiones de inicio del Caballero de la Muerte."
#define LOCALE_LICHKING_7 "Deseo saltarme la línea de misiones de inicio del Caballero de la Muerte."
#define LOCALE_LICHKING_8 "Я хочу пропустить начальную цепочку заданий Рыцаря Смерти."

class Azerothcore_optional_deathknight_skip : public CreatureScript
{
public:
    Azerothcore_optional_deathknight_skip() : CreatureScript("npc_ac_skip_lich") { }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (creature->IsQuestGiver())
            {
                player->PrepareQuestMenu(creature->GetGUID());
            }

            if (sConfigMgr->GetOption<bool>("Skip.Deathknight.Optional.Enable", true))
            {
                char const* localizedEntry;
                switch (player->GetSession()->GetSessionDbcLocale())
                {
                case LOCALE_koKR: localizedEntry = LOCALE_LICHKING_1; break;
                case LOCALE_frFR: localizedEntry = LOCALE_LICHKING_2; break;
                case LOCALE_deDE: localizedEntry = LOCALE_LICHKING_3; break;
                case LOCALE_zhCN: localizedEntry = LOCALE_LICHKING_4; break;
                case LOCALE_zhTW: localizedEntry = LOCALE_LICHKING_5; break;
                case LOCALE_esES: localizedEntry = LOCALE_LICHKING_6; break;
                case LOCALE_esMX: localizedEntry = LOCALE_LICHKING_7; break;
                case LOCALE_ruRU: localizedEntry = LOCALE_LICHKING_8; break;
                case LOCALE_enUS: localizedEntry = LOCALE_LICHKING_0; break;
                default: localizedEntry = LOCALE_LICHKING_0;
                }
                AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, localizedEntry, GOSSIP_SENDER_MAIN, 11);
            }
            player->TalkedToCreature(creature->GetEntry(), creature->GetGUID());
            SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*menuId*/, uint32 gossipListId) override
        {
            int DKL = sConfigMgr->GetOption<float>("Skip.Deathknight.Start.Level", 58);
            CloseGossipMenuFor(player);
            ClearGossipMenuFor(player);
            switch (gossipListId)
            {
            case 11:
                AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "Yes", GOSSIP_SENDER_MAIN, 12);
                AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "No", GOSSIP_SENDER_MAIN, 13);
                SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
                break;

            case 12:
                if (player->getLevel() <= DKL)
                {
                    player->GiveLevel(DKL);
                }
                player->learnSpell(53428, false);//runeforging
                player->learnSpell(53441, false);//runeforging
                player->learnSpell(53344, false);//runeforging
                player->learnSpell(62158, false);//runeforging
                player->learnSpell(33391, false);//journeyman riding
                player->learnSpell(54586, false);//runeforging credit
                player->learnSpell(48778, false);//acherus deathcharger
                player->learnSkillRewardedSpells(776, 375);//Runeforging
                player->learnSkillRewardedSpells(960, 375);//Runeforging

                if (player->GetQuestStatus(12657) == QUEST_STATUS_NONE)//The Might Of The Scourge
                {
                    player->AddQuest(sObjectMgr->GetQuestTemplate(12657), nullptr);
                    player->RewardQuest(sObjectMgr->GetQuestTemplate(12657), false, player);
                }
                if (player->GetQuestStatus(12801) == QUEST_STATUS_NONE)//The Light of Dawn
                {
                    player->AddQuest(sObjectMgr->GetQuestTemplate(12801), nullptr);
                    player->RewardQuest(sObjectMgr->GetQuestTemplate(12801), false, player);
                }
                if (player->GetTeamId() == TEAM_ALLIANCE && player->GetQuestStatus(13188) == QUEST_STATUS_NONE)//Where Kings Walk
                {
                    player->AddQuest(sObjectMgr->GetQuestTemplate(13188), nullptr);
                    player->RewardQuest(sObjectMgr->GetQuestTemplate(13188), false, player);
                }
                else if (player->GetTeamId() == TEAM_HORDE && player->GetQuestStatus(13189) == QUEST_STATUS_NONE)//Saurfang's Blessing
                {
                    player->AddQuest(sObjectMgr->GetQuestTemplate(13189), nullptr);
                    player->RewardQuest(sObjectMgr->GetQuestTemplate(13189), false, player);
                }
                player->TeleportTo(571, 5806.69f, 642.95f, 609.89f, 4.02f);//Dalaran
                ObjectAccessor::SaveAllPlayers();//Save
                CloseGossipMenuFor(player);
                break;

            case 13://close
                CloseGossipMenuFor(player);
                break;

            default:

                break;
            }
            return true;
        }
};

void AddSkipDKScripts()
{
    new AzerothCore_skip_deathknight_announce;
    new AzerothCore_skip_deathknight;
    new Azerothcore_optional_deathknight_skip;
}
