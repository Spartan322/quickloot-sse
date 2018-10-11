#include "GameFunctions.h"

// 1.5.16 = +0x80 bytes from 1.5.3

/*
Ref:
33 DB 41 0F B6 F0 8B FB 48 85 C0 74 1E
xxxxxxxxxxxxx
-0x13

1_5_53 NOTES:
Address: 0x7FF7A680E453

SkyrimSE.exe+28E453 - 33 DB                 - xor ebx,ebx
SkyrimSE.exe+28E455 - 41 0FB6 F0            - movzx esi,r8l
SkyrimSE.exe+28E459 - 8B FB                 - mov edi,ebx
SkyrimSE.exe+28E45B - 48 85 C0              - test rax,rax
SkyrimSE.exe+28E45E - 74 1E                 - je SkyrimSE.exe+28E47E

-0x13, don't know the original purpose of this but it seems to lead to which seems about right.
SkyrimSE.exe+28E440 - 48 89 5C 24 08        - mov [rsp+08],rbx

*/
RelocAddr<TESObjectREFR_GetInventoryItemCount_t*> TESObjectREFR_GetInventoryItemCount (0x0028E440); // 1_5_53

/*
00007FF644240DC7 | 48 C7 44 24 30 00 00 00 00   | mov qword ptr ss:[rsp+30],0                              |
00007FF644240DD0 | 48 8D 54 24 30               | lea rdx,qword ptr ss:[rsp+30]                            |
00007FF644240DD5 | 48 8B C8                     | mov rcx,rax                                              |
00007FF644240DD8 | E8 E3 23 89 FF               | call skyrimse.7FF643AD31C0                               | < =================== TESObjectREFR_LookupRefByHandle
00007FF644240DDD | 90                           | nop                                                      |
00007FF644240DDE | 48 8B 5C 24 30               | mov rbx,qword ptr ss:[rsp+30]                            |
00007FF644240DE3 | 48 85 DB                     | test rbx,rbx                                             |
00007FF644240DE6 | 74 3A                        | je skyrimse.7FF644240E22                                 |
00007FF644240DE8 | 45 33 C0                     | xor r8d,r8d                                              |
00007FF644240DEB | 48 8B 15 66 F6 5B 02         | mov rdx,qword ptr ds:[7FF646800458]                      |
00007FF644240DF2 | 48 8B CB                     | mov rcx,rbx                                              |
00007FF644240DF5 | E8 76 C3 C5 FF               | call skyrimse.7FF643E9D170                               |
00007FF644240DFA | 8B 83 E0 00 00 00            | mov eax,dword ptr ds:[rbx+E0]                            |
00007FF644240E00 | C1 E8 1E                     | shr eax,1E                                               |
00007FF644240E03 | A8 01                        | test al,1                                                |
00007FF644240E05 | 75 35                        | jne skyrimse.7FF644240E3C                                |
00007FF644240E07 | 45 33 C9                     | xor r9d,r9d                                              |
00007FF644240E0A | 4C 8B 05 47 F6 5B 02         | mov r8,qword ptr ds:[7FF646800458]                       |
00007FF644240E11 | 48 8B D3                     | mov rdx,rbx                                              |
00007FF644240E14 | 48 8B 8B F0 00 00 00         | mov rcx,qword ptr ds:[rbx+F0]                            |
00007FF644240E1B | E8 90 D7 CC FF               | call skyrimse.7FF643F0E5B0                               |
00007FF644240E20 | EB 1A                        | jmp skyrimse.7FF644240E3C                                |
00007FF644240E22 | 48 8B 07                     | mov rax,qword ptr ds:[rdi]                               |
00007FF644240E25 | 41 B9 01 00 00 00            | mov r9d,1                                                |
00007FF644240E2B | 44 8B C6                     | mov r8d,esi                                              |
00007FF644240E2E | 48 8D 15 4B 21 D7 00         | lea rdx,qword ptr ds:[7FF644FB2F80]                      | 7FF644FB2F80:"No nearby NPC found to sound alarm, alarm aborted."
00007FF644240E35 | 48 8B CF                     | mov rcx,rdi                                              |
00007FF644240E38 | FF 50 10                     | call qword ptr ds:[rax+10]                               |*/

/*
1_5_53 NOTES:

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

1_5_53 NOTES:

Reference:
48 0F 44 D6 48 85 D2 0F 85 XX XX XX XX 48 85 C0 0F 85

Found:
48 0F 44 D6 48 85 D2 0F 85 BE 00 00 00 48 85 C0 0F 85
at address 7FF7A682688E / SkyrimSE.exe+2A688E

-0x2E:
SkyrimSE.exe+2A6860 - 40 57                 - push rdi

*/
RelocAddr<TESForm_GetOwner_t*> TESForm_GetOwner (0x002A6860); // 1_5_53



/*
Ref:
48 85 C9 0F 84 C1 00 00 00 0F B6 41 1A 83 C0 E9 83 F8 1D 0F 87 B1 00 00 00
-0x16

1_5_53 NOTES:

Reference:
48 85 C9 0F 84 C1 00 00 00 0F B6 41 1A 83 C0 E9 83 F8 1D 0F 87 B1 00 00 00

Found:
48 85 C9 0F 84 C1 00 00 00 0F B6 41 1A 83 C0 E9 83 F8 1D 0F 87 B1 00 00 00
at address 7FF7A6721936 / SkyrimSE.exe+1A1936

-0x16:
SkyrimSE.exe+1A1920 - 40 53                 - push rbx
*/
RelocAddr<TESForm_GetWeight_t*>  TESForm_GetWeight (0x001A1920); // 1_5_53

/*
Ref:
48 85 D2 74 2F 8B 4B 0C FF C9 8B 44 24 48 48 23 C8 48 8D 04 49 48 8D 04 C2 48 83 78 10 00 74 14
-0x4C

1_5_53 NOTES:

Found:
48 85 D2 74 2F 8B 4B 0C FF C9 8B 44 24 48 48 23 C8 48 8D 04 49 48 8D 04 C2 48 83 78 10 00 74 14
at address 7FF7A671446C

-0x4C:
SkyrimSE.exe+194420 - 40 57                 - push rdi
*/
RelocAddr<TESForm_LookupFormByID_t*>   TESForm_LookupFormByID (0x00194420); // 1_5_53

/*
00007FF7295D72F0 | 48 8D 15 B9 61 2F 01         | lea rdx,qword ptr ds:[7FF72A8CD4B0]                      | 7FF72A8CD4B0:"Found ReferenceHandle extra on invalid %s ref '%s' (%08X)"
00007FF7295D72F7 | B9 05 00 00 00               | mov ecx,5                                                |
00007FF7295D72FC | E8 BF 28 EF FF               | call skyrimse.7FF7294C9BC0                               |
00007FF7295D7301 | BA 1C 00 00 00               | mov edx,1C                                               |
00007FF7295D7306 | 49 8D 4E 70                  | lea rcx,qword ptr ds:[r14+70]                            |
00007FF7295D730A | E8 71 C3 EA FF               | call skyrimse.7FF729483680                               |
00007FF7295D730F | 90                           | nop                                                      |
00007FF7295D7310 | 48 85 DB                     | test rbx,rbx                                             |
00007FF7295D7313 | 74 1C                        | je skyrimse.7FF7295D7331                                 |
00007FF7295D7315 | 48 8D 4B 20                  | lea rcx,qword ptr ds:[rbx+20]                            |
00007FF7295D7319 | 83 C8 FF                     | or eax,FFFFFFFF                                          |
00007FF7295D731C | F0 0F C1 41 08               | lock xadd dword ptr ds:[rcx+8],eax                       |
00007FF7295D7321 | FF C8                        | dec eax                                                  |
00007FF7295D7323 | A9 FF 03 00 00               | test eax,3FF                                             |
00007FF7295D7328 | 75 07                        | jne skyrimse.7FF7295D7331                                |
00007FF7295D732A | 48 8B 01                     | mov rax,qword ptr ds:[rcx]                               |
00007FF7295D732D | FF 50 08                     | call qword ptr ds:[rax+8]                                |
00007FF7295D7330 | 90                           | nop                                                      |
00007FF7295D7331 | 41 F7 47 40 20 00 00 08      | test dword ptr ds:[r15+40],8000020                       |
00007FF7295D7339 | 74 49                        | je skyrimse.7FF7295D7384                                 |
00007FF7295D733B | 49 8D 4E 70                  | lea rcx,qword ptr ds:[r14+70]                            |
00007FF7295D733F | E8 7C 96 E9 FF               | call skyrimse.7FF7294709C0                               |
00007FF7295D7344 | 49 8B CE                     | mov rcx,r14                                              |
00007FF7295D7347 | E8 24 1C F5 FF               | call skyrimse.7FF729528F70                               |
00007FF7295D734C | 48 85 C0                     | test rax,rax                                             |
00007FF7295D734F | 74 0D                        | je skyrimse.7FF7295D735E                                 |
00007FF7295D7351 | 49 8B D7                     | mov rdx,r15                                              |
00007FF7295D7354 | 48 8B C8                     | mov rcx,rax                                              |
00007FF7295D7357 | E8 C4 51 F6 FF               | call skyrimse.7FF72953C520                               |
00007FF7295D735C | EB 26                        | jmp skyrimse.7FF7295D7384                                |
00007FF7295D735E | 49 8B D6                     | mov rdx,r14                                              |
00007FF7295D7361 | 48 8D 4C 24 48               | lea rcx,qword ptr ss:[rsp+48]                            |
00007FF7295D7366 | E8 C5 1F F5 FF               | call skyrimse.7FF729529330                               | < ====== ctor
00007FF7295D736B | 90                           | nop                                                      |
00007FF7295D736C | 49 8B D7                     | mov rdx,r15                                              |
00007FF7295D736F | 48 8D 4C 24 48               | lea rcx,qword ptr ss:[rsp+48]                            |
00007FF7295D7374 | E8 A7 51 F6 FF               | call skyrimse.7FF72953C520                               |
00007FF7295D7379 | 90                           | nop                                                      |
00007FF7295D737A | 48 8D 4C 24 48               | lea rcx,qword ptr ss:[rsp+48]                            |
00007FF7295D737F | E8 9C 20 F5 FF               | call skyrimse.7FF729529420                               |< ======= dtor
00007FF7295D7384 | 41 8B 47 40                  | mov eax,dword ptr ds:[r15+40]                            |
*/

/*
1_5_53 NOTES:

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

1_5_53 NOTES:

Found:
33 FF 44 8B E7 48 8B 49 08 0F B7 D7 66 89 55 40 48 85 C9 74 15 8B C7 80 79 1A 3E
at address 7FF7A6769FB2 / SkyrimSE.exe+1E9FB2

-0x32:
SkyrimSE.exe+1E9F80 - 40 55                 - push rbp
*/
RelocAddr<ECCData_InitContainer_t*> ECCData_InitContainer (0x001E9F80); // 1_5_53


/*
Ref:
65 48 8B 04 25 58 00 00 00 B9 68 07 00 00 4E 8B 34 C0 4C 03 F1 41 8B 3E 89 7C 24 60 41 C7 06 61 00 00 00 49 8D 5F 10 48 89 5C 24 68 48 8B CB
first entry

1_5_53 NOTES:

Found:
65 48 8B 04 25 58 00 00 00 B9 68 07 00 00 4E 8B 34 C0 4C 03 F1 41 8B 3E 89 7C 24 60 41 C7 06 61 00 00 00 49 8D 5F 10 48 89 5C 24 68 48 8B CB
at address 7FF7A668F7D7 - 7FF7A668F7EF

SkyrimSE.exe+10F7D7 - 65 48 8B 04 25 58000000  - mov rax,gs:[00000058] { 88 }
SkyrimSE.exe+10F7E0 - B9 68070000           - mov ecx,00000768 { 1896 }
SkyrimSE.exe+10F7E5 - 4E 8B 34 C0           - mov r14,[rax+r8*8]
SkyrimSE.exe+10F7E9 - 4C 03 F1              - add r14,rcx
SkyrimSE.exe+10F7EC - 41 8B 3E              - mov edi,[r14]
SkyrimSE.exe+10F7EF - 89 7C 24 60           - mov [rsp+60],edi

*/
RelocAddr<BaseExtraList_SetInventoryChanges_t*> BaseExtraList_SetInventoryChanges (0x0010F7D7); // 1_5_53


/*
Ref:
48 85 FF 74 06 0F B7 47 10 EB 05 B8 01 00 00 00 48 8B 5C 24 48 48 83 C4 30 5F C3
-0x47

1_5_53 NOTES:

Found:
48 85 FF 74 06 0F B7 47 10 EB 05 B8 01 00 00 00 48 8B 5C 24 48 48 83 C4 30 5F C3
at address 7FF7A66939E7

-0x47:
SkyrimSE.exe+1139A0 - 40 57                 - push rdi
*/
RelocAddr<BaseExtraList_GetItemCount_t*>	    BaseExtraList_GetItemCount (0x001139A0); // 1_5_53

/*
Ref:
48 8B 59 08 48 85 DB 74 22 48 8B 1B 48 85 DB 74 1A 48 8B CB
first match

1_5_53 NOTES:

Found:
48 8B 59 08 48 85 DB 74 22 48 8B 1B 48 85 DB 74 1A 48 8B CB
at address 7FF7A6756816

SkyrimSE.exe+1D6816 - 48 8B 59 08           - mov rbx,[rcx+08]
*/
RelocAddr<InventoryEntryData_GetOwner_t*>		 InventoryEntryData_GetOwner (0x001D6816); // 1_5_53

/*
Ref:
48 8B F0 48 85 C0 75 04 48 8B 73 40 33 C0 80 7E 1A 2B 48 0F 44 C6 48 3B EE 0F 84 80 00 00 00 80 7D 1A 0B
-0x4D

1_5_53 NOTES:

Found:
48 8B F0 48 85 C0 75 04 48 8B 73 40 33 C0 80 7E 1A 2B 48 0F 44 C6 48 3B EE 0F 84 80 00 00 00 80 7D 1A 0B
at address 7FF7A67577CD - 7FF7A67577E5

-0x4D:
SkyrimSE.exe+1D7780 - 48 89 5C 24 10        - mov [rsp+10],rbx
*/
RelocAddr<InventoryEntryData_IsOwnedBy_t*>		InventoryEntryData_IsOwnedBy (0x001D7780); // 1_5_53

/*
Ref:
48 8B 59 08 40 32 FF 48 85 DB 74 4A 48 89 74 24 30 0F 1F 44 00 00 48 83 7B 08 00 75 06
-0xA

1_5_53 NOTES:

Found:
48 8B 59 08 40 32 FF 48 85 DB 74 4A 48 89 74 24 30 0F 1F 44 00 00 48 83 7B 08 00 75 06
at address 7FF7A6756D9A

-0xA:
SkyrimSE.exe+1D6D90 - 48 89 5C 24 10        - mov [rsp+10],rbx
*/
RelocAddr<InventoryEntryData_IsQuestItem_t*>    InventoryEntryData_IsQuestItem (0x001D6D90); // 1_5_53

/*
Ref:
49 89 5B 10 49 89 73 18 33 C0 49 89 43 D8
-0x10

1_5_53 NOTES:

Found:
49 89 5B 10 49 89 73 18 33 C0 49 89 43 D8
at address 7FF7A6681EC0

-0x10:
SkyrimSE.exe+101EB0 - 4C 8B DC              - mov r11,rsp
*/
RelocAddr<MagicItem_GetCostliestEffectItem_t*>	 MagicItem_GetCostliestEffectItem (0x00101EB0); // 1_5_53