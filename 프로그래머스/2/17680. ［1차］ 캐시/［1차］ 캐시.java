import java.util.*;
class Info implements Comparable<Info>{
    String city;
    Integer time;
    Info(String city, Integer time){
        this.city = city;
        this.time = time;
    }
    
    public int compareTo(Info other){
        return time - other.time;
    }
}

class Solution {
    Map<String, Integer> m = new HashMap<>();//도시,시간
    PriorityQueue<Info> pq = new PriorityQueue<>();
    
    void cache(int cacheSize, String newCity, int time){
        // int cnt = 0;
        if(cacheSize == 0) return;
        if(m.size() < cacheSize){
            m.put(newCity, time);
            return;
        }
        
        String target = null;
        for(String city : m.keySet()){
            // if(m.getOrDefault(city, -1) == -1) continue;
            
            // cnt++;
            if(m.getOrDefault(target, 1000000) > m.get(city)) target = city;
        }
        m.remove(target);
        m.put(newCity, time);
    }
    
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        
        for(int i=0;i<cities.length;i++){
            String city = cities[i].toLowerCase();

            //캐시 히트
            if(m.getOrDefault(city, -1) != -1){
                answer += 1;
                m.put(city, i);
                continue;
            }
            //캐시미스
            answer += 5;
            cache(cacheSize, city, i);
            
        }
        return answer;
    }
}