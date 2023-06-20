//
// Created by kyleyannelli on 6/19/23.
//

#include "env_loader.h"
#include <fstream>
#include <sstream>

std::map<std::string, std::string> env_loader::load(const std::string& filename)
{
    std::map<std::string, std::string> env; // create the map of String to String

    std::ifstream file(filename); // load the file from the filename
    std::string current_line; // hold the current line
    while(std::getline(file, current_line)) // continues until there are no more lines in the file
    {
        std::stringstream ss(current_line); // create a stream from the current line, so we can easily manipulate it
        std::string key, value; // init key pairs

        // ss is a stream so pulling the content to '=' will make key point to it, then doing the same for value
        //  but since key and = were already pulled from the stream it's the stuff after the =
        if(std::getline(ss, key, '=') && std::getline(ss, value))
        {
            env[key] = value;
        }
    }
    return env;
}