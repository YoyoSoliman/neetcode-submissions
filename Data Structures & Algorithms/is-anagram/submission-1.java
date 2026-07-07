class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() == t.length()) {

            
            for (int k = 0; k < s.length() ; k++) {
                int oc_1 = 0;
                int oc_2 = 0;
                char c = s.charAt(k);
                for(int i = 0; i < s.length(); i++){
                    if(c == s.charAt(i)) {
                        oc_1++;
                    }
                    if (c == t.charAt(i)) {
                        oc_2++;   
                    }
                }
                if (oc_1 != oc_2) {
                    return false;
                }           
            }

            return true;
        
        }
        return false;
    }
}
