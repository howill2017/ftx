    public String m83716c(Map<String, String> map) {
        StringBuilder sb2 = new StringBuilder();
        try {
            if (map.size() > 0) {
                sb2.append("?");
                ArrayList<Map.Entry> arrayList = new ArrayList(map.entrySet());
                Collections.sort(arrayList, new a());
                for (Map.Entry entry : arrayList) {
                    String str = (String) entry.getValue();
                    if (!C20157h0.m84997u0(str)) {
                        String encode = "NULL".equals(str) ? URLEncoder.encode("", "UTF-8") : URLEncoder.encode(str, "UTF-8");
                        sb2.append((String) entry.getKey());
                        sb2.append("=");
                        sb2.append(encode);
                        sb2.append("&");
                    }
                }
                sb2.deleteCharAt(sb2.length() - 1);
            }
        } catch (UnsupportedEncodingException e10) {
            e10.printStackTrace();
        }
        if (!C20157h0.m84997u0(sb2.toString()) || sb2.toString().length() > 0) {
            sb2.append("&wirelesscode=" + SouFunSec.getSec(sb2.toString().substring(1, sb2.toString().length())));
        }
        return sb2.toString();
    }



    public static String m13338h(Map<String, String> map, boolean z10) {
        StringBuilder sb2 = new StringBuilder();
        try {
            if (map.size() > 0) {
                sb2.append("?");
                ArrayList<Map.Entry> arrayList = new ArrayList(map.entrySet());
                Collections.sort(arrayList, new g());
                for (Map.Entry entry : arrayList) {
                    String str = (String) entry.getValue();
                    if (!C5121i0.m13727l(str)) {
                        String encode = "NULL".equals(str) ? URLEncoder.encode("", "utf-8") : URLEncoder.encode(str, "utf-8");
                        sb2.append((String) entry.getKey());
                        sb2.append("=");
                        sb2.append(encode);
                        sb2.append("&");
                    }
                }
                sb2.deleteCharAt(sb2.length() - 1);
            }
        } catch (UnsupportedEncodingException e10) {
            e10.printStackTrace();
        }
        if (!C5121i0.m13727l(sb2.toString()) || sb2.toString().length() > 0) {
            String substring = sb2.toString().substring(1, sb2.toString().length());
            try {
                substring = C5131n0.f18342b ? SFBroadCastSec.getSec(substring) : SFBroadCastSec.getSecNew(substring);
            } catch (Exception e11) {
                e11.printStackTrace();
            }
            if (!z10) {
                return substring;
            }
            sb2.append("&wirelesscode=" + substring);
        }
        return sb2.toString();
    }
