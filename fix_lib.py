import os
import re
import shutil

def copy_and_rename_latest_lib(path, lib):

    lib_pattern = re.compile(lib[:lib.rfind('.lib')] + r'-\d+.lib$')
    print(lib_pattern)

    matches = []

    for f in os.listdir(path):
        if re.match(lib_pattern, f):
            matches.append(f)

    matches.sort()

    if len(matches) == 0:
        print("WARNING, COULDNT FIND A LIB.")

    latest_lib = matches[-1]
    latest_lib = os.path.join(path, latest_lib)
    output_lib = os.path.join(path, lib)

    shutil.copy(latest_lib, output_lib)


def main():
    path1 = "Source/Plugins/DomainRandomizationDNN/Intermediate/Build/Win64/UE4Editor/Development/DomainRandomizationDNN"
    lib1 = "UE4Editor-DomainRandomizationDNN.lib"

    path2 = "Source/Plugins/NVSceneCapturer/Intermediate/Build/Win64/UE4Editor/Development/NVSceneCapturer"
    lib2 = "UE4Editor-NVSceneCapturer.lib"

    copy_and_rename_latest_lib(path1, lib1)
    copy_and_rename_latest_lib(path2, lib2)

if __name__ == "__main__":
    main()