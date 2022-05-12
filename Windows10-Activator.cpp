#include <iostream>
#include <string>
#include <map>
#include <Windows.h>


std::map<std::string, std::string> keys {
    {"Home", "TX9XD-98N7V-6WMQ6-BX7FG-H8Q99"},
    {"Home N", "3KHY7-WNT83-DGQKR-F7HPR-844BM"},
    {"Home Single Language", "7HNRX-D7KGG-3K4RQ-4WPJ4-YTDFH"},
    {"Home Country Specific", "PVMJN-6DFY6-9CCP6-7BKTT-D3WVR"},
    {"Professional", "W269N-WFGWX-YVC9B-4J6C9-T83GX"},
    {"Professional N", "MH37W-N47XK-V7XM9-C7227-GCQG9"},
    {"Education", "NW6C2-QMPVW-D7KKK-3GKT6-VCFB2"},
    {"Education N", "2WH4N-8QGBV-H22JP-CT43Q-MDWWJ"},
    {"Enterprise", "NPPR9-FWDCX-D2C8J-H872K-2YT43"},
    {"Enterprise N", "DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4"},
};

// Credit: https://stackoverflow.com/a/8196291
BOOL IsElevated() {
    BOOL fRet = FALSE;
    HANDLE hToken = NULL;
    if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
        TOKEN_ELEVATION Elevation;
        DWORD cbSize = sizeof(TOKEN_ELEVATION);
        if (GetTokenInformation(hToken, TokenElevation, &Elevation, sizeof(Elevation), &cbSize)) {
            fRet = Elevation.TokenIsElevated;
        }
    }
    if (hToken) {
        CloseHandle(hToken);
    }
    return fRet;
}

int main()
{
    std::cout << "[+] Windows 10 Activator" << std::endl;

    if (!IsElevated())
    {
        std::cout << "[!] Please restart with administrator permissions" << std::endl;
        system("pause");
        exit(134);
    }

    std::cout << "\n[+] Select windows version:" << std::endl;

    int idx = 1;
    for (auto i = keys.begin(); i != keys.end(); ++i) {
        std::cout << idx << " : " << i->first << std::endl;
        ++idx;
    }

    std::cout << "\n[+] Enter number according to Windows version: ";

    int os;
    std::cin >> os;
    if (os > 0) --os;

    auto key = keys.begin();
    std::advance(key, os);
    std::cout << "Using key " << key->second << " for " << key->first << std::endl << std::endl;

    std::string installLicenseKeyCmd = "slmgr /ipk " + key->second;
    std::string setKMSMachineAddressCmd = "slmgr /skms s8.uk.to";
    std::string activateWindowsCmd = "slmgr /ato";

    std::cout << "[-] " << installLicenseKeyCmd << std::endl;
    std::cout << "[-] " << setKMSMachineAddressCmd << std::endl;
    std::cout << "[-] " << activateWindowsCmd << std::endl << std::endl;

    system(installLicenseKeyCmd.c_str());
    system(setKMSMachineAddressCmd.c_str());
    system(activateWindowsCmd.c_str());

    system("pause");
}
