from collections import defaultdict

f = open("./7.in")

sizes = defaultdict(lambda: 0)
associated_dirs = defaultdict(lambda: [])
cwd = '/'
for line in f:
    line = line.strip()
    parts = line.split(" ")
    if (parts[0] == '$'):
        if (parts[1] == 'cd'):
            if parts[2] == '/':
                cwd = '/'
            elif parts[2] == '..':
                cwd = cwd[0:cwd.rindex('/')]
            else:
                if cwd != "/":
                    cwd += "/"
                cwd += parts[2]
    elif parts[0] == 'dir':
        if cwd != '/':
            associated_dirs[cwd].append(cwd + "/" + parts[1])
            sizes[cwd+"/"+parts[1]] = 0
        else:
            associated_dirs[cwd].append(cwd + parts[1])
            sizes[cwd+parts[1]] = 0
    else:
        sizes[cwd] += int(parts[0])
        for key in sizes.keys():
            if cwd.startswith(key) and key != cwd:
                sizes[key] += int(parts[0])

totalSize = 0
for key in sizes.keys():
    if sizes[key] <= 100000:
        totalSize += sizes[key]
print("part 1:", totalSize)

totalStorage = 70000000
totalStorageUsed = sizes["/"]
storageNeeded = 30000000 - (totalStorage - totalStorageUsed)
enough_room = filter(lambda x: x >= storageNeeded, sizes.values())
print("part 2: ", min(enough_room))

f.close()
