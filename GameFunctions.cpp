#include "GameFunctions.h"

/*
Ref:
33 DB 41 0F B6 F0 8B FB 48 85 C0 74 1E
xxxxxxxxxxxxx
-0x13
*/
RelocAddr<TESObjectREFR_GetInventoryItemCount_t*> TESObjectREFR_GetInventoryItemCount (0x0028E440); // 1_5_53

/*
SkyrimSE.exe+982BE7 - 48 C7 44 24 30 00000000 - mov qword ptr [rsp+30],00000000 { 0 }
SkyrimSE.exe+982BF0 - 48 8D 54 24 30        - lea rdx,[rsp+30]
SkyrimSE.exe+982BF5 - 48 8B C8              - mov rcx,rax
SkyrimSE.exe+982BF8 - E8 E30689FF           - call SkyrimSE.exe+2132E0									   | < =================== TESObjectREFR_LookupRefByHandle SkyrimSE.exe+2132E0
SkyrimSE.exe+982BFD - 90                    - nop
SkyrimSE.exe+982BFE - 48 8B 5C 24 30        - mov rbx,[rsp+30]
SkyrimSE.exe+982C03 - 48 85 DB              - test rbx,rbx
SkyrimSE.exe+982C06 - 74 3A                 - je SkyrimSE.exe+982C42
SkyrimSE.exe+982C08 - 45 33 C0              - xor r8d,r8d
SkyrimSE.exe+982C0B - 48 8B 15 E6B25C02     - mov rdx,[SkyrimSE.exe+2F4DEF8] { [1A0ACBBE290] }
SkyrimSE.exe+982C12 - 48 8B CB              - mov rcx,rbx
SkyrimSE.exe+982C15 - E8 E6BDC5FF           - call SkyrimSE.exe+5DEA00
SkyrimSE.exe+982C1A - 8B 83 E0000000        - mov eax,[rbx+000000E0]
SkyrimSE.exe+982C20 - C1 E8 1E              - shr eax,1E { 30 }
SkyrimSE.exe+982C23 - A8 01                 - test al,01 { 1 }
SkyrimSE.exe+982C25 - 75 35                 - jne SkyrimSE.exe+982C5C
SkyrimSE.exe+982C27 - 45 33 C9              - xor r9d,r9d
SkyrimSE.exe+982C2A - 4C 8B 05 C7B25C02     - mov r8,[SkyrimSE.exe+2F4DEF8] { [1A0ACBBE290] }
SkyrimSE.exe+982C31 - 48 8B D3              - mov rdx,rbx
SkyrimSE.exe+982C34 - 48 8B 8B F0000000     - mov rcx,[rbx+000000F0]
SkyrimSE.exe+982C3B - E8 00D2CCFF           - call SkyrimSE.exe+64FE40
SkyrimSE.exe+982C40 - EB 1A                 - jmp SkyrimSE.exe+982C5C
SkyrimSE.exe+982C42 - 48 8B 07              - mov rax,[rdi]
SkyrimSE.exe+982C45 - 41 B9 01000000        - mov r9d,00000001 { 1 }
SkyrimSE.exe+982C4B - 44 8B C6              - mov r8d,esi
SkyrimSE.exe+982C4E - 48 8D 15 EB86D700     - lea rdx,[SkyrimSE.exe+16FB340] { ["No nearby NPC found to sound alarm, alarm aborted."] }
SkyrimSE.exe+982C55 - 48 8B CF              - mov rcx,rdi
SkyrimSE.exe+982C58 - FF 50 10              - call qword ptr [rax+10]
*/
RelocAddr<TESObjectREFR_LookupRefByHandle_t*>     TESObjectREFR_LookupRefByHandle   (0x002132E0); // 1_5_53

/*
Ref:
48 0F 44 D6 48 85 D2 0F 85 00 00 00 00 48 85 C0 0F 85
xxxxxxxxx????xxxxx
-0x2E
*/
RelocAddr<TESForm_GetOwner_t*> TESForm_GetOwner (0x002A6860); // 1_5_53

/*
Ref:
48 85 C9 0F 84 C1 00 00 00 0F B6 41 1A 83 C0 E9 83 F8 1D 0F 87 B1 00 00 00
-0x16
*/
RelocAddr<TESForm_GetWeight_t*>  TESForm_GetWeight (0x001A1920); // 1_5_53

/*
Ref:
48 85 D2 74 2F 8B 4B 0C FF C9 8B 44 24 48 48 23 C8 48 8D 04 49 48 8D 04 C2 48 83 78 10 00 74 14
-0x4C
*/
RelocAddr<TESForm_LookupFormByID_t*>   TESForm_LookupFormByID (0x00194420); // 1_5_53

/*
SkyrimSE.exe+287410 - 48 8D 15 19E12F01     - lea rdx,[SkyrimSE.exe+1585530] { ["Found ReferenceHandle extra on invalid %s ref '%s' (%08X)"] }
SkyrimSE.exe+287417 - B9 05000000           - mov ecx,QuickLootSSE._Init_thread_epoch+1 { 00000005 }
SkyrimSE.exe+28741C - E8 8F28EFFF           - call SkyrimSE.exe+179CB0
SkyrimSE.exe+287421 - BA 1C000000           - mov edx,0000001C { 28 }
SkyrimSE.exe+287426 - 49 8D 4E 70           - lea rcx,[r14+70]
SkyrimSE.exe+28742A - E8 41C3EAFF           - call SkyrimSE.exe+133770
SkyrimSE.exe+28742F - 90                    - nop
SkyrimSE.exe+287430 - 48 85 DB              - test rbx,rbx
SkyrimSE.exe+287433 - 74 1C                 - je SkyrimSE.exe+287451
SkyrimSE.exe+287435 - 48 8D 4B 20           - lea rcx,[rbx+20]
SkyrimSE.exe+287439 - 83 C8 FF              - or eax,-01 { 255 }
SkyrimSE.exe+28743C - F0 0FC1 41 08         - lock xadd [rcx+08],eax
SkyrimSE.exe+287441 - FF C8                 - dec eax
SkyrimSE.exe+287443 - A9 FF030000           - test eax,000003FF { 1023 }
SkyrimSE.exe+287448 - 75 07                 - jne SkyrimSE.exe+287451
SkyrimSE.exe+28744A - 48 8B 01              - mov rax,[rcx]
SkyrimSE.exe+28744D - FF 50 08              - call qword ptr [rax+08]
SkyrimSE.exe+287450 - 90                    - nop
SkyrimSE.exe+287451 - 41 F7 47 40 20000008  - test [r15+40],8000020 { 134217760 }
SkyrimSE.exe+287459 - 74 49                 - je SkyrimSE.exe+2874A4
SkyrimSE.exe+28745B - 49 8D 4E 70           - lea rcx,[r14+70]
SkyrimSE.exe+28745F - E8 4C96E9FF           - call SkyrimSE.exe+120AB0
SkyrimSE.exe+287464 - 49 8B CE              - mov rcx,r14
SkyrimSE.exe+287467 - E8 C41BF5FF           - call SkyrimSE.exe+1D9030
SkyrimSE.exe+28746C - 48 85 C0              - test rax,rax
SkyrimSE.exe+28746F - 74 0D                 - je SkyrimSE.exe+28747E
SkyrimSE.exe+287471 - 49 8B D7              - mov rdx,r15
SkyrimSE.exe+287474 - 48 8B C8              - mov rcx,rax
SkyrimSE.exe+287477 - E8 B451F6FF           - call SkyrimSE.exe+1EC630
SkyrimSE.exe+28747C - EB 26                 - jmp SkyrimSE.exe+2874A4
SkyrimSE.exe+28747E - 49 8B D6              - mov rdx,r14
SkyrimSE.exe+287481 - 48 8D 4C 24 48        - lea rcx,[rsp+48]
SkyrimSE.exe+287486 - E8 651FF5FF           - call SkyrimSE.exe+1D93F0                               | < ====== ctor SkyrimSE.exe+1D93F0
SkyrimSE.exe+28748B - 90                    - nop
SkyrimSE.exe+28748C - 49 8B D7              - mov rdx,r15
SkyrimSE.exe+28748F - 48 8D 4C 24 48        - lea rcx,[rsp+48]
SkyrimSE.exe+287494 - E8 9751F6FF           - call SkyrimSE.exe+1EC630
SkyrimSE.exe+287499 - 90                    - nop
SkyrimSE.exe+28749A - 48 8D 4C 24 48        - lea rcx,[rsp+48]
SkyrimSE.exe+28749F - E8 3C20F5FF           - call SkyrimSE.exe+1D94E0                               |< ======= dtor SkyrimSE.exe+1D94E0
SkyrimSE.exe+2874A4 - 41 8B 47 40           - mov eax,[r15+40]
*/
RelocAddr<ECCData_ctor_t*>  ECCData_ctor (0x001D93F0); // 1_5_53
RelocAddr<ECCData_dtor_t*>  ECCData_dtor (0x001D94E0); // 1_5_53

/*
Ref:
33 FF 44 8B E7 48 8B 49 08 0F B7 D7 66 89 55 40 48 85 C9 74 15 8B C7 80 79 1A 3E
-0x32
*/
RelocAddr<ECCData_InitContainer_t*> ECCData_InitContainer (0x001E9F80); // 1_5_53


/*
Ref:
65 48 8B 04 25 58 00 00 00 B9 68 07 00 00 4E 8B 34 C0 4C 03 F1 41 8B 3E 89 7C 24 60 41 C7 06 61 00 00 00 49 8D 5F 10 48 89 5C 24 68 48 8B CB
first entry
*/
RelocAddr<BaseExtraList_SetInventoryChanges_t*> BaseExtraList_SetInventoryChanges (0x0010F7B0); // 1_5_53


/*
Ref:
48 85 FF 74 06 0F B7 47 10 EB 05 B8 01 00 00 00 48 8B 5C 24 48 48 83 C4 30 5F C3
-0x47
*/
RelocAddr<BaseExtraList_GetItemCount_t*>	    BaseExtraList_GetItemCount (0x001139A0); // 1_5_53

/*
Ref:
48 8B 59 08 48 85 DB 74 22 48 8B 1B 48 85 DB 74 1A 48 8B CB
first match
*/
RelocAddr<InventoryEntryData_GetOwner_t*>		 InventoryEntryData_GetOwner (0x001D6810); // 1_5_53

/*
Ref:
48 8B F0 48 85 C0 75 04 48 8B 73 40 33 C0 80 7E 1A 2B 48 0F 44 C6 48 3B EE 0F 84 80 00 00 00 80 7D 1A 0B
-0x4D
*/
RelocAddr<InventoryEntryData_IsOwnedBy_t*>		InventoryEntryData_IsOwnedBy (0x001D7780); // 1_5_53

/*
Ref:
48 8B 59 08 40 32 FF 48 85 DB 74 4A 48 89 74 24 30 0F 1F 44 00 00 48 83 7B 08 00 75 06
-0xA
*/
RelocAddr<InventoryEntryData_IsQuestItem_t*>    InventoryEntryData_IsQuestItem (0x001D6D90); // 1_5_53

/*
Ref:
49 89 5B 10 49 89 73 18 33 C0 49 89 43 D8
-0x10
*/
RelocAddr<MagicItem_GetCostliestEffectItem_t*>	 MagicItem_GetCostliestEffectItem (0x00101EB0); // 1_5_53