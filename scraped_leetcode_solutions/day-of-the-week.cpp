class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        string weekday[7];
        weekday[0] = "Sunday";
        weekday[1] = "Monday";
        weekday[2] = "Tuesday";
        weekday[3] = "Wednesday";
        weekday[4] = "Thursday";
        weekday[5] = "Friday";
        weekday[6] = "Saturday";
        
        int day_diff = 0;
        
        for(int i = 1971;i < year;i++){
            day_diff += 365;
            if(i % 4 == 0)
                day_diff++;
        }
        
        for(int i = 1; i < month;i++){
            switch(i){
                case 1:
                    day_diff += 31;
                    break;
                case 2:
                    if(year % 4 == 0)
                        day_diff++;
                    day_diff += 28;
                    break;
                case 3:
                    day_diff += 31;
                    break;
                case 4:
                    day_diff += 30;
                    break;
                case 5:
                    day_diff += 31;
                    break;
                case 6:
                    day_diff += 30;
                    break;
                case 7:
                    day_diff += 31;
                    break;
                case 8:
                    day_diff += 31;
                    break;
                case 9:
                    day_diff += 30;
                    break;
                case 10:
                    day_diff += 31;
                    break;
                case 11:
                    day_diff += 30;
                    break;
            }
        }
        
        day_diff += (5 + day - 1);
        day_diff %= 7;
        return weekday[day_diff];
        
    }
};