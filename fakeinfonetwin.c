#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <process.h>

#define DELIM "."
#define StringLength32bit    (36/4)
#define StringLength128bit (128/4)

char *split(const char *str, size_t size){
    static const char *p=NULL;
    char *temp;
    int i;
    if(str != NULL) p=str;
    if(p==NULL || *p=='\0') return NULL;
    temp=(char*)malloc((size+1)*sizeof(char));
    for(i=0;*p && i<size;++i){
        temp[i]=*p++;
    }
    temp[i]='\0';
    return temp;
}

/*



E:\BlajarC>gcc -c -DBUILD_DLL fakeinfonetwin.c

E:\BlajarC>gcc -shared -o fakeinfonetwin.dll fakeinfonetwin.c

E:\BlajarC>gcc -shared -o fakeinfonetwin.dll fakeinfonetwin.o -Wl,--add-stdcall-alias


void thing(void) {
    char tagstr[60] = "";
    const char *pad = "";
    int k; fakeinfonetwin.c
    int n = 5;
    for (k = 0; k < n; k++)
    {
        char temp[10]  = "";
        snprintf(temp, sizeof(temp), "%sval%d", pad, k);
        strcat(tagstr, temp); // copy ulang space
        pad = ":";
    }
    printf("tagstr <<%s>>\n", tagstr);
}*/

int valid_digit(char* ip_str)
{
    while (*ip_str) {
        if (*ip_str >= '0' && *ip_str <= '9')
            ++ip_str;
        else
            return 0;
    }
    return 1;
}

/* return 1 if IP string is valid, else return 0 */
int is_valid_ip(char* ip_str)
{
    int i, num, dots = 0;
    char* ptr;

    if (ip_str == NULL)
        return 0;

    ptr = strtok(ip_str, DELIM);

    if (ptr == NULL)
        return 0;

    while (ptr) {

        /* after parsing string, it must contain only digits */
        if (!valid_digit(ptr))
            return 0;

        num = atoi(ptr);

        /* check for valid IP */
        if (num >= 0 && num <= 255) {
            /* parse remaining string */
            ptr = strtok(NULL, DELIM);
            if (ptr != NULL)
                ++dots;
        }
        else
            return 0;
    }

    /* valid IP string must contain 3 dots */
    if (dots != 3)
        return 0;
    return 1;
}
void Hexadecimal_32bit(char destination[20]){
    int value;
    int length;
    char str[20] = "0123456789ABCDEF";
    char testing[1200];
    //destination = "0x";
    /* Seed number for rand() */
    srand((unsigned int) time(0) + getpid());
    length = (rand() % (15-12))+12;
 
    while(1) {
        //printf("%c", str[rand() % 16]);
        str[(rand() % (20-2))+2] = str[rand() % 16];
        value = atoi(str);
        sprintf(testing, "%x", value);
        if ( strlen(testing) ==7 || strlen(testing) ==8 ){
            strcat(destination, testing);
            break;
        }
        srand(rand());
    }
   
}
void Hexadecimal_32bits(char destination[20]){
    char cStrHex[(StringLength32bit+1)] = {0};

    // Seed random:
    srand((unsigned int) time(0));

    // Fill the char buffer
    int i=0;
    for(; i < StringLength32bit; i++){
        sprintf(cStrHex+i, "%x", rand() % 16);
    }
    strcat(destination, cStrHex);
    // Print hex string:
    //printf("%s\n", cStrHex);
}
void Hexadecimal_128bits(char destinations[20]){
    char cStrHex[(StringLength128bit+1)] = {0};

    // Seed random:
    srand((unsigned int) time(0));

    // Fill the char buffer
    int i=0;
    for(; i < StringLength128bit; i++){
        sprintf(cStrHex+i, "%x", rand() % 16);
    }
    strcat(destinations, cStrHex);
    // Print hex string:
    //printf("%s\n", cStrHex);
}

char *randomBinaryText(int n)
{
    char *outputxs;
    if (n <= 0)
    {
        return 0;
    }
    // Use to collect result
    char record[n + 1];
    for (int i = 0; i < n; ++i)
    {
        // Collect the random number
        record[i] = '0' + ((rand()) % 2);
    }
    record[n] = '\0';
    outputxs = strdup(record);
    return outputxs;
}

char *Binarytohex(char *hexadec){
    char *a = hexadec;
    char outputxs[48], *outputs;
    int num = 0;
    do {
        int b = *a=='1'?1:0;
        num = (num<<1)|b;
        a++;
    } while (*a);
    snprintf(outputxs, sizeof(outputxs), "%X", num);
    outputs = strdup(outputxs);
    return outputs;
}


char* print_ip(int ip) {
   unsigned char bytes[4];
   char buf[256];
   char snum[20];
   char *stringsx;
   int i;
   printf("%d\n", ip);
   for(i=0; i<4; i++) {
      bytes[i] = (ip >> i*8) & 0xFF;
   }

    snprintf(buf, sizeof(buf),"%d.%d.%d.%d", bytes[3], bytes[2], bytes[1], bytes[0]);
    snprintf(snum, sizeof(snum), "%s", buf);
    stringsx = strdup(snum);
    return stringsx;
   //itoa(num, snum, 10);
}

//char* IP_v4(){
  //  char destination[20] = "0x";;
    //Hexadecimal_32bit(destination);
    //int cheat = (int)destination;
    //char *hello = print_ip(cheat);
    //return hello;
//}
char* IP_v4(){
    char destination[20] = "0x";
    Hexadecimal_32bits(destination);
    char *outputxs = print_ip(destination);
    return outputxs;
}

char* IP_v6(){
    char destinations[128] = "", *outputxs, snum[128],
    *out, *temp[128];
    Hexadecimal_128bits(destinations);
    out =  strdup(destinations);

    char tagstr[128] = "";
    const char *pad = "";
    int i,j;

    for(i=0;NULL!=(out=split(out, 4));out=NULL)
        temp[i++]=out;

    for(j=0;j<i;++j){
        char trash[128]  = "";
        snprintf(trash, sizeof(trash), "%s%s", pad, temp[j]);
        strcat(tagstr, trash); 
        pad = ":";
        free(temp[j]);
    }
    outputxs = strdup(tagstr);
    return outputxs;

}

char *mac(){
    char *product, *lenghts2, *lenghts3, *lenghts4, *lenghts5, *lenghts6, buf[48];
    while(1){
        product = Binarytohex(randomBinaryText(8));
        if (strlen(product)==2){
            break;
        }
    }
    while(1){
        lenghts2 = Binarytohex(randomBinaryText(8));
        if (strlen(lenghts2)==2){
            break;
        }
    }
    while(1){
        lenghts3 = Binarytohex(randomBinaryText(8));
        if (strlen(lenghts3)==2){
            break;
        }
    }
    while(1){
        lenghts4 = Binarytohex(randomBinaryText(8));
        if (strlen(lenghts4)==2){
            break;
        }
    }
    while(1){
        lenghts5 = Binarytohex(randomBinaryText(8));
        if (strlen(lenghts5)==2){
            break;
        }
    }
    while(1){
        lenghts6 = Binarytohex(randomBinaryText(8));
        if (strlen(lenghts6)==2){
            break;
        }
    }
    snprintf(buf, sizeof(buf), "%s:%s:%s:%s:%s:%s", product,  lenghts2, lenghts3, lenghts4, lenghts5, lenghts6);
    product = strdup(buf);
    return product;
}


////check class ip


char findClass(char str[])
{
    // storing first octet in arr[] variable
    char arr[4];
    int i = 0;
    while (str[i] != '.')
    {
        arr[i] = str[i];
        i++;
    }
    i--;
 
    // converting str[] variable into number for
    // comparison
    int ip = 0, j = 1;
    while (i >= 0)
    {
        ip = ip + (str[i] - '0') * j;
        j = j * 10;
        i--;
    }
 
    // Class A
    if (ip >=1 && ip <= 126)
        return 'A';
 
    // Class B
    else if (ip >= 128 && ip <= 191)
        return 'B';
 
    // Class C
    else if (ip >= 192 && ip <= 223)
        return 'C';
 
    // Class D
    else if (ip >= 224 && ip <= 239)
        return 'D';
 
    // Class E
    else
        return 'E';
}
 
// Function to separate Network ID as well as
// Host ID and print them
void separate(char str[], char ipClass[2])
{
    // Initializing network and host array to NULL
    char network[12], host[12];
    for (int k = 0; k < 12; k++)
        network[k] = host[k] = '\0';
 
    // for class A, only first octet is Network ID
    // and rest are Host ID
    if (*ipClass == 'A')
    {
        int i = 0, j = 0;
        while (str[j] != '.')
            network[i++] = str[j++];
        i = 0;
        j++;
        while (str[j] != '\0')
            host[i++] = str[j++];
        printf("Network ID is %s\n", network);
        printf("Host ID is %s\n", host);
    }
 
    // for class B, first two octet are Network ID
    // and rest are Host ID
    else if (*ipClass == 'B')
    {
        int i = 0, j = 0, dotCount = 0;
 
        // storing in network[] up to 2nd dot
        // dotCount keeps track of number of
        // dots or octets passed
        while (dotCount < 2)
        {
            network[i++] = str[j++];
            if (str[j] == '.')
                dotCount++;
        }
        i = 0;
        j++;
 
        while (str[j] != '\0')
            host[i++] = str[j++];
 
        printf("Network ID is %s\n", network);
        printf("Host ID is %s\n", host);
    }
 
    // for class C, first three octet are Network ID
    // and rest are Host ID
    else if (*ipClass == 'C')
    {
        int i = 0, j = 0, dotCount = 0;
 
        // storing in network[] up to 3rd dot
        // dotCount keeps track of number of
        // dots or octets passed
        while (dotCount < 3)
        {
            network[i++] = str[j++];
            if (str[j] == '.')
                dotCount++;
        }
 
        i = 0;
        j++;
 
        while (str[j] != '\0')
            host[i++] = str[j++];
 
        printf("Network ID is %s\n", network);
        printf("Host ID is %s\n", host);
    }
 
    // Class D and E are not divided in Network
    // and Host ID
    else
        printf("In this Class, IP address is not"
           " divided into Network and Host ID\n");
}


void IPv4(char * param) {
    srand(time(NULL));
    char add[128];
    char *xx = IP_v4();
    sprintf(add, "%s", xx); 
    strncat(param, add, 128);
}

void IPv6(char * param) {
    srand(time(NULL));
    char add[128];
    char *xx = IP_v6();
    sprintf(add, "%s", xx); 
    strncat(param, add, 128);
}

void Mac_Address(char * param) {
    srand(time(NULL));
    char add[128];
    char *xx = mac();
    sprintf(add, "%s", xx); 
    strncat(param, add, 128);
}


void main()
{

    char *xx = IP_v4();
    char xpss[20];
    sprintf(xpss, "%s", xx); 
    char ipClass = findClass(xpss);
    printf("%s  %c\n", xpss, ipClass);
    separate(xpss, ipClass);
    printf("%s\n", IP_v6());
    srand(time(NULL));
    printf("%s\n",mac());

}