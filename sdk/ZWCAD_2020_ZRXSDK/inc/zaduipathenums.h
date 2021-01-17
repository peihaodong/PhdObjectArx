

#pragma once

#pragma pack (push, 8)

typedef enum {
    PATH_NOERR = 0,
    PATH_INVALID,        
    PATH_BADOP,          
    PATH_REFUSED,        
    PATH_ERR            
} PathErr;

typedef enum {
    NO_PATH = 0,        
    NEW_PATH,           
    WC_PATH,            
    FILE_PATH,          
    DIR_PATH,           
    DEV_PATH,           
} path_type;

enum path_category {
    DRIVE_TYPE,         
    UNC_TYPE,           
    ROOT_TYPE,          
    RELATIVE_TYPE       
};

#pragma pack (pop)

