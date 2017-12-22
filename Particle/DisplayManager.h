#include <stdlib.h>
#include <string>
namespace Display{
    class DisplayManager
    {
        public:
        DisplayManager();
        ~DisplayManager();

        void CreateDisplay(int width, int height, char* title);
        void DeleteDisplay();

    };
}