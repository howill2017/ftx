jstring __fastcall Java_com_soufun_app_sec_SouFunSec_getSec(JNIEnv *env, jobject obj, jstring strText)
{
  unsigned int v3; // w0
  int i; // [xsp+34h] [xbp-13Ch]
  char *v6; // [xsp+38h] [xbp-138h]
  jstring v7; // [xsp+40h] [xbp-130h]
  char *p; // [xsp+48h] [xbp-128h]
  char *b; // [xsp+50h] [xbp-120h]
  char *a; // [xsp+58h] [xbp-118h]
  jstring v13; // [xsp+78h] [xbp-F8h]
  char dest[16]; // [xsp+90h] [xbp-E0h] BYREF
  __int128 v15; // [xsp+A0h] [xbp-D0h]
  char v16; // [xsp+B0h] [xbp-C0h]
  unsigned __int8 digest[16]; // [xsp+B8h] [xbp-B8h] BYREF
  MD5_CTX md5; // [xsp+C8h] [xbp-A8h] BYREF
  char key[65]; // [xsp+120h] [xbp-50h] BYREF
  __int64 v20; // [xsp+168h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(TPIDR_EL0) + 40);
  reflectInit(env);
  a = Jstring2CStr(env, strText);
  strcpy(&key[48], "(xfhB;Vov(y;Cddl");
  *(_OWORD *)&key[32] = xmmword_1022;
  *(_OWORD *)&key[16] = xmmword_1012;
  *(_OWORD *)key = xmmword_1002;
  encrypt(key, strKey);
  if ( !phonemessage )
    phonemessage = "error";
  b = join(phonemessage, key);
  p = join(a, b);
  free(b);
  v7 = (*env)->NewStringUTF(env, p);
  free(p);
  v6 = (char *)((__int64 (__fastcall *)(JNIEnv *, jstring))(*env)->GetStringUTFChars)(env, v7);
  MD5Init(&md5);
  v3 = __strlen_chk(v6, 0xFFFFFFFFFFFFFFFFLL);
  MD5Update(&md5, (unsigned __int8 *)v6, v3);
  MD5Final(&md5, digest);
  v16 = 0;
  v15 = 0u;
  *(_OWORD *)dest = 0u;
  for ( i = 0; i <= 15; ++i )
  {
    printf("%02x", digest[i]);
    sprintf(dest, 0x21u, "%s%02X", dest, digest[i]);
  }
  if ( flag == 1 )
    v13 = (*env)->NewStringUTF(env, dest);
  else
    v13 = (*env)->NewStringUTF(env, "error");
  _ReadStatusReg(TPIDR_EL0);
  return v13;
}
