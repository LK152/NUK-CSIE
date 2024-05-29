#include<stdio.h>
#include<string.h>

int digitValue(char x) {
    if(x>='0' && x<='9') return x-'0';
    if(x>='A' && x<='Z') return x-'A'+10;
    if(x>='a' && x<='z') return x-'a'+36;
}

int main() {
    char str[1024];
    while(scanf("%s",str) == 1) {
        int ans=0, base=0, sum=0, i, len = strlen(str);
        if ((len == 1 && str[0] == '0') || (len == 2 && (str[0] == '-'|| str[0] == '+') && str[1] == '0')) {
                printf("2\n");
                continue;
        }

        for(i = 0;str[i];i++) {
            if(str[i] == '-' || str[i]=='+') continue;
            int val = digitValue(str[i]);
            sum += val;
            if(val > base) base = val;
        }

        for(i = base;i<=61 && !ans;i++) if(!(sum % i)) ans=i+1;

        if(ans) printf("%d\n",ans);
        else printf("such number is impossible!\n");
    }

    return 0;
}
