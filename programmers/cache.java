//https://school.programmers.co.kr/learn/courses/30/lessons/17680
import java.util.ArrayList;

class Solution {
    static int cacheSize_ =0;
    static ArrayList<String> cache = new ArrayList<>();
    
    static int seekCity (String upperS) {
        if (cache.size() == 0){                    
            return -1;
        }
        
        for (int i=0; i < cache.size(); i++){
            if (cache.get(i).equals(upperS)){
                return i;
            }
        }
        
        return -1;
    }
    
    static boolean isHit(String s){
        if (cacheSize_ == 0){                    
            return false;
        }
        
        String upperS = s.toUpperCase();
        int cityIdx = seekCity(upperS);
        
        // hit
        if (cityIdx > -1) {
            cache.remove(cityIdx);
            cache.add(upperS);
            return true;
        }        
        
        // miss
        if (cache.size() == cacheSize_)
            cache.remove(0);            
        cache.add(upperS);
        return false;
    } 
    
    public int solution(int cacheSize, String[] cities) {
        if (cacheSize==0) return cities.length * 5;
        
        cacheSize_ = cacheSize;
        int answer = 0;
        
        for (String city : cities){
            if (isHit(city)) 
                answer+=1;
            else 
                answer+=5;
        }
        
        return answer;
    }
}