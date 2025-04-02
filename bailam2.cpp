#include <stdio.h>

struct Date {
    int month;  
    int day;    
};

int getMaxDays(int month) {
    if (month == 2) return 28;
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    return 31;
}

struct Date initDate(int month, int day) {
    struct Date d;
    if (month >= 1 && month <= 12 && day >= 1 && day <= getMaxDays(month)) {
        d.month = month;
        d.day = day;
    } else {
        d.month = 1;
        d.day = 1;
    }
    return d;
}

struct Date increaseDay(struct Date d) {
    d.day++; 
    
    if (d.day > getMaxDays(d.month)) {
        d.day = 1;   
        d.month++;   
        
        if (d.month > 12) {
            d.month = 1;
        }
    }
    return d;
}

int dateDifference(struct Date d1, struct Date d2) {
    int days1 = 0, days2 = 0;
    
    for (int i = 1; i < d1.month; i++) {
        days1 += getMaxDays(i);
    }
    days1 += d1.day;
    
    for (int i = 1; i < d2.month; i++) {
        days2 += getMaxDays(i);
    }
    days2 += d2.day;
    
    int diff = days1 - days2;
    if (diff < 0) diff = -diff;
    return diff;
}

int main() {
    struct Date d1 = initDate(3, 15);  
    printf("Date 1: %d/%d\n", d1.month, d1.day);
    
    struct Date d2 = increaseDay(d1);  
    printf("After increase: %d/%d\n", d2.month, d2.day);
    
    struct Date d3 = initDate(4, 30);  
    struct Date d4 = increaseDay(d3);   
    printf("From 4/30 to: %d/%d\n", d4.month, d4.day);
    
    int diff = dateDifference(d1, d2);
    printf("Difference between %d/%d and %d/%d: %d days\n", 
           d1.month, d1.day, d2.month, d2.day, diff);
    
    return 0;
}
