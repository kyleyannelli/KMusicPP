//
// Created by kyleyannelli on 6/19/23.
//

#ifndef KMUSICPP_ENV_LOADER_H
#define KMUSICPP_ENV_LOADER_H

#include <string>
#include <map>

class env_loader {
public:
    static std::map<std::string, std::string> load(const std::string& filename);
};


#endif //KMUSICPP_ENV_LOADER_H
