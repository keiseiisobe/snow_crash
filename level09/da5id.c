
/* WARNING: Removing unreachable block (ram,0x00101503) */

undefined4 main(int param_1,undefined8 *param_2)

{
  int *piVar1;
  char cVar2;
  ushort uVar3;
  ushort uVar4;
  ushort *puVar5;
  bool bVar6;
  __pid_t _Var7;
  __uid_t _Var8;
  uint uVar9;
  time_t __time0;
  time_t __time1;
  ulong uVar10;
  ushort **ppuVar11;
  char *pcVar12;
  char *pcVar13;
  FILE *__stream;
  char *pcVar14;
  size_t sVar15;
  long lVar16;
  ulong uVar17;
  char *pcVar18;
  ulong extraout_RDX;
  ulong uVar19;
  ulong uVar20;
  byte *pbVar21;
  undefined4 *puVar22;
  byte bVar23;
  byte bVar24;
  uint uVar25;
  undefined4 uVar26;
  long in_FS_OFFSET;
  byte bVar27;
  double dVar28;
  double __x;
  double dVar29;
  char local_708 [128];
  char local_688 [136];
  ulong local_600;
  ulong local_5f8;
  uint local_5f0;
  double local_5e8;
  undefined4 local_5e0;
  uint local_5dc;
  time_t local_5d8;
  __pid_t local_5d0;
  __uid_t local_5cc;
  uint local_5c8;
  uint local_5c4;
  undefined1 local_5c0;
  undefined8 local_5bf;
  undefined8 local_5b7;
  undefined4 local_5af [245];
  byte local_1d8 [143];
  char acStack_149 [265];
  long local_40;
  
  bVar27 = 0;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_1 != 2) {
    __fprintf_chk(stderr,2,"Usage: %s <token>\n",*param_2);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  __time0 = time((time_t *)0x0);
  _Var7 = getpid();
  _Var8 = getuid();
  time((time_t *)0x0);
  getuid();
  getpid();
  __time1 = time((time_t *)0x0);
  if (-1 < __time1) {
    difftime(__time1,__time0);
  }
  pcVar14 = (char *)param_2[1];
  pcVar18 = local_708;
  pcVar12 = pcVar18;
  for (lVar16 = 0x26; lVar16 != 0; lVar16 = lVar16 + -1) {
    pcVar12[0] = '\0';
    pcVar12[1] = '\0';
    pcVar12[2] = '\0';
    pcVar12[3] = '\0';
    pcVar12[4] = '\0';
    pcVar12[5] = '\0';
    pcVar12[6] = '\0';
    pcVar12[7] = '\0';
    pcVar12 = pcVar12 + ((ulong)bVar27 * -2 + 1) * 8;
  }
  local_600 = strlen(pcVar14);
  if (local_600 - 1 < 0x80) {
    memcpy(pcVar18,pcVar14,local_600);
    uVar20 = local_600;
    uVar10 = 0;
    local_708[local_600] = '\0';
    uVar17 = 0;
    if (uVar20 != 0) {
      do {
        if ((local_688[uVar10 + 1] != ' ') && (local_688[uVar10 + 1] != '\t')) {
          if (uVar10 < uVar20) {
            uVar17 = 0;
            goto LAB_0010142d;
          }
          break;
        }
        uVar10 = uVar10 + 1;
      } while (uVar20 != uVar10);
      uVar17 = 0;
    }
LAB_001013b2:
    do {
      uVar20 = uVar17;
      if (uVar20 == 0) goto LAB_001013b7;
      uVar17 = uVar20 - 1;
    } while ((local_688[uVar20] == ' ') || (local_688[uVar20] == '\t'));
    local_688[uVar20 + 1] = '\0';
    pcVar14 = pcVar18 + uVar20;
    local_5e0 = 1;
    local_5f8 = uVar20;
    ppuVar11 = __ctype_b_loc();
    puVar5 = *ppuVar11;
    pcVar12 = pcVar18;
    do {
      if ((*(byte *)((long)puVar5 + (ulong)(byte)pcVar12[0x81] * 2 + 1) & 0x40) == 0) {
        fwrite("Token contains non-printable characters.\n",1,0x29,stderr);
        goto LAB_001014d1;
      }
      pcVar12 = pcVar12 + 1;
    } while (pcVar14 != pcVar12);
    pbVar21 = (byte *)&local_5d8;
    for (lVar16 = 0x80; pcVar12 = pcVar18, lVar16 != 0; lVar16 = lVar16 + -1) {
      pbVar21[0] = 0;
      pbVar21[1] = 0;
      pbVar21[2] = 0;
      pbVar21[3] = 0;
      pbVar21[4] = 0;
      pbVar21[5] = 0;
      pbVar21[6] = 0;
      pbVar21[7] = 0;
      pbVar21 = pbVar21 + ((ulong)bVar27 * -4 + 2) * 4;
    }
    do {
      pcVar13 = pcVar12 + 1;
      piVar1 = (int *)((long)&local_5d8 + (ulong)(byte)pcVar12[0x81] * 4);
      *piVar1 = *piVar1 + 1;
      pcVar12 = pcVar13;
    } while (pcVar13 != pcVar14);
    dVar29 = 0.0;
    pbVar21 = (byte *)&local_5d8;
    do {
      if (*(int *)pbVar21 != 0) {
        __x = (double)*(int *)pbVar21 / (double)(long)uVar20;
        dVar28 = log(__x);
        dVar29 = dVar29 - (dVar28 / 0.6931471805599453) * __x;
      }
      pbVar21 = pbVar21 + 4;
    } while (local_1d8 != pbVar21);
    uVar9 = 0xdeadbeef;
    local_5e8 = dVar29;
    pcVar12 = pcVar18;
    do {
      pbVar21 = (byte *)(pcVar12 + 0x81);
      pcVar12 = pcVar12 + 1;
      uVar9 = ((uVar9 << 3 | uVar9 >> 0x1d) ^ (uint)*pbVar21) + (uint)*pbVar21 * -0x61c88647;
      uVar9 = uVar9 ^ uVar9 >> 0x10;
    } while (pcVar14 != pcVar12);
    uVar9 = uVar9 ^ (uint)uVar20;
    uVar9 = (uVar9 ^ uVar9 >> 0xd) * -0x3d4d51cb;
    uVar9 = uVar9 ^ uVar9 >> 0x10;
    local_5f0 = uVar9;
    uVar3 = puVar5[(byte)local_688[1]];
    local_5dc = (uint)((uVar3 & 0x800) == 0);
    if (3 < uVar20) {
      bVar23 = 0;
      pbVar21 = (byte *)&local_5d8;
      for (lVar16 = 0x80; lVar16 != 0; lVar16 = lVar16 + -1) {
        pbVar21[0] = 0;
        pbVar21[1] = 0;
        pbVar21[2] = 0;
        pbVar21[3] = 0;
        pbVar21[4] = 0;
        pbVar21[5] = 0;
        pbVar21[6] = 0;
        pbVar21[7] = 0;
        pbVar21 = pbVar21 + ((ulong)bVar27 * -4 + 2) * 4;
      }
      bVar24 = 0;
      bVar6 = false;
      uVar25 = 0;
      do {
        uVar17 = (ulong)(byte)pcVar18[0x81];
        uVar4 = puVar5[uVar17];
        if ((uVar4 & 0x400) != 0) {
          bVar6 = true;
        }
        if ((uVar4 & 0x100) != 0) {
          bVar24 = 1;
        }
        if ((uVar4 & 0x200) != 0) {
          bVar23 = 1;
        }
        if (*(int *)((long)&local_5d8 + uVar17 * 4) == 0) {
          *(undefined4 *)((long)&local_5d8 + uVar17 * 4) = 1;
          uVar25 = uVar25 + 1;
        }
        pcVar18 = pcVar18 + 1;
      } while (pcVar14 != pcVar18);
      if ((((bVar6) && (!(bool)(bVar24 ^ 1) && !(bool)(bVar23 ^ 1))) && ((uVar3 & 0x800) == 0)) &&
         ((3 < uVar25 && (1.5 <= dVar29)))) {
        uVar17 = 0;
        do {
          uVar10 = uVar17;
          local_1d8[uVar10] = local_688[uVar10 + 1] ^ 0x5a;
          uVar17 = uVar10 + 1;
        } while (uVar10 + 1 != uVar20);
        uVar20 = 0;
        local_1d8[uVar10 + 1] = 0;
        local_5d8 = time((time_t *)0x0);
        local_5c4 = 0xffffffff;
        local_5c0 = 0;
        local_5b7 = 0;
        local_5bf = 0x676e69646e6570;
        puVar22 = local_5af;
        for (lVar16 = 0xc; local_5d0 = _Var7, local_5cc = _Var8, local_5c8 = uVar9, lVar16 != 0;
            lVar16 = lVar16 + -1) {
          *puVar22 = 0;
          puVar22 = puVar22 + (ulong)bVar27 * -2 + 1;
        }
        do {
          __printf_chk(2,"checking byte %d...\n",uVar20 & 0xffffffff);
          fflush(stdout);
          if (local_688[uVar20 + 1] != "Iheartpwnage"[uVar20]) {
            local_5c4 = 0xffffffff;
            local_5c0 = (undefined1)uVar20;
            uVar20 = uVar20 & 0xff;
            uVar17 = extraout_RDX;
            goto LAB_0010182c;
          }
          uVar20 = uVar20 + 1;
        } while (uVar20 != 0xc);
        local_5c0 = 0xc;
        local_5c4 = -(uint)(local_688[0xd] != '\0');
        uVar17 = (ulong)local_5c4;
        if (local_688[0xd] == '\0') {
          __snprintf_chk(&local_5bf,0x40,2,0x40,"accepted fp=%08x",uVar9);
          s_audit_head = (s_audit_head + 1) % 0x10;
          if (s_audit_count < 0x10) {
            s_audit_count = s_audit_count + 1;
          }
          __stream = fopen("/home/flag09/.flag","r");
          uVar26 = 0;
          if (__stream == (FILE *)0x0) {
            fwrite("access error\n",1,0xd,stderr);
          }
          else {
            pcVar18 = acStack_149 + 1;
            pcVar14 = fgets(pcVar18,0x100,__stream);
            if (pcVar14 != (char *)0x0) {
              sVar15 = strlen(pcVar18);
              while (sVar15 != 0) {
                sVar15 = sVar15 - 1;
                if ((pcVar18[sVar15] != '\n') && (pcVar18[sVar15] != '\r')) break;
                pcVar18[sVar15] = '\0';
              }
              __printf_chk(2,"TOKEN ACCEPTED.\nFlag: %s\n",pcVar18);
            }
            fclose(__stream);
          }
          goto LAB_001014d7;
        }
        uVar20 = 0xc;
LAB_0010182c:
        __snprintf_chk(&local_5bf,0x40,2,0x40,"rejected at byte %u fp=%08x",uVar20,uVar9,uVar17);
        s_audit_head = (s_audit_head + 1) % 0x10;
        if (s_audit_count < 0x10) {
          s_audit_count = s_audit_count + 1;
        }
        fwrite("Invalid token.\n",1,0xf,stderr);
        goto LAB_001014d1;
      }
    }
LAB_001013b7:
    fwrite("Token does not meet policy requirements.\n",1,0x29,stderr);
  }
  else {
    fwrite("Token format error.\n",1,0x14,stderr);
  }
LAB_001014d1:
  uVar26 = 1;
LAB_001014d7:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar26;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_0010142d:
  cVar2 = pcVar18[uVar17 + uVar10];
  if ((cVar2 == '\r') || (cVar2 == '\n')) goto LAB_001013b2;
  uVar19 = uVar17 + 1;
  local_688[uVar17 + 1] = cVar2;
  uVar17 = uVar19;
  if ((uVar20 - uVar10 == uVar19) || (uVar19 == 0x80)) goto LAB_001013b2;
  goto LAB_0010142d;
}
