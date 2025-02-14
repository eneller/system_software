#include <unistd.h>
#include <fcntl.h>

int main(){
    const char hello[] = "Fett";
    int fd = open("./writetest.txt",O_RDWR | O_CREAT);
    if(write(fd, hello,sizeof(hello)-1) ==-1 ){
        return 1;
    }
}