#include <stdio.h>
#include <time.h>

int main() {

    time_t now;
    struct tm *local_time;
    now = time(NULL);
    local_time = localtime(&now);

    while (1) {

        int current_hour = local_time->tm_hour;

        if (current_hour < 12) {
            printf("Alert: Good Morning\n");
        } else if (current_hour >= 12 && current_hour < 18) {
            printf("Alert: Good Afternoon\n");
        } else {
            printf("Alert: Good Night\n");
        }


        sleep(3600);
        now = time(NULL);
        local_time = localtime(&now);
    }
}
