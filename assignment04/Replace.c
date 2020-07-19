#include <stdio.h>
#include <stdlib.h>

//Diana Lin, 260625972

int StringLength(char *str) {
//from Lecture slides
    int i;
    for (i=0; *str != '\n'; i++, str++);
    return i;
}
int StringEqual(char *s1, char *s2) {
//from Lecture Slides
    for (; *s1 != '\0' && *s2 != '\0' && *s1==*s2; s1++, s2++);
    return *s1-*s2;
}

void StringCopy(char *source, char *target) {
//DUPLICATES a char array, DOES NOT WORK to append
    int count = 0;
    while(source[count] != '\0') {
        target[count] = source[count];
        count++;
    }
}

void FindRecord(char *filename, char *name, char record[]){
    FILE *phonebook = fopen(filename,"rt");
    char line[1000] = {'\0'}; 
    fgets(line,999,phonebook);       
    while (!feof(phonebook)) {
        //check names
        char recName[1000] = {'\0'};
        int count = 0;
        while (line[count] != ',') {
            recName[count] = line[count];
            //will break out of this loop when a comma is encountered (aka name!)
            count++;
        }
        recName[count] = '\n';
        //since inputted name has a new line character, must add one to the recName
        //stores the name in the record
        if (StringEqual(name,recName) == 0) {
            //copy line into record
            StringCopy(line,record);
            printf("Match found!\n");
            fclose(phonebook);
            return;
        }
    for(int i =0; i < 1000; i++) {
        line[i] = '\0';
    }
    fgets(line,999,phonebook);
    }
    printf("Match not found.\n");
    fclose(phonebook);
    exit(-1);
        
}

void Replace(char *name, char *newname, char record[]) {
    //copy record[] into a temp array
    char temp[1000] = {'\0'};
    StringCopy(record, temp);
    //record = {'\0'};
    //copy new name into record first, without \n
    char letter = ' ';
    int i;
    for(i = 0; letter != '\n'; i++) {
        letter = *(newname + i);
        *(record + i) = letter;
    }
    //write the comma in
    i--;
    *(record+i) = ',';
    i++;
    int length = StringLength(name);
    //find length of OLD name, and start the pointer there
    letter = ' ';
    for (int j = length+1; letter != '\0'; j++) {
        letter = *(temp + j);
        *(record + i) = letter;
        i++;
    }
}

void SaveRecord(char *filename, char *name, char record[]) {
    system("cp phonebook.csv temp.csv");
    FILE *read = fopen("temp.csv","rt");
    FILE *write = fopen(filename, "wt");
    char line[1000] = {'\0'};
    fgets(line,999,read);
    while (!feof(read)) {
        //check names
        char recName[1000] = {'\0'};
        int count = 0;
        
        while (line[count] != ',') {
            recName[count] = line[count];
            count++;
        }
        recName[count] = '\n';
        if (StringEqual(name, recName) == 0) {
            fputs(record, write);
        }
        else {
            fputs(line, write);
        }
        //reset line to null so it can be used again
        for (int i = 0; i < 1000; i++) { 
            line[i] = '\0';
        }
        fgets(line,999,read);
    }
    fclose(write);
    fclose(read);     
}

int main() {
	//ask for a name
    char nameArr[1000] = {'\0'};
    char *name = nameArr;
    printf("All names are case sensitive.\nInput your name: ");
    fgets(name, 999, stdin);
    
	//ask for a replacement name
    char rnameArr[1000] = {'\0'};
    char *rname = rnameArr;
    printf("Input your replacement name: ");
    fgets(rname,999,stdin);
    char *filename = "phonebook.csv";
    char record[1000] = {'\0'};
    //invoke FindRecord
    FindRecord(filename, name, record);
    //invoke Replace
    Replace(name, rname, record);
    //invoke SaveRecord
    SaveRecord(filename, name, record);
    return 0;
}
