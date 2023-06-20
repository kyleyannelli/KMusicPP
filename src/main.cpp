#include <iostream>
#include "env_loader.h"

int main()
{
    auto env = env_loader::load(".env");

    std::cout << env["DISCORD_BOT_TOKEN"];
}
