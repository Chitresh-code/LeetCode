bool rotateString(char * s, char * goal){
    if(strlen(s) != strlen(goal)) return false;
    
    char *doubleS = calloc(sizeof(char), (strlen(s) * 2 + 2));
    
    // form the concatenation of given string s to itself
    strcat(doubleS, s);
    strcat(doubleS, s);
    
    // goal should be a substring in doubleS if s is rotated version of goal
    if(strstr(doubleS, goal))
        return true;
        
    return false;
}