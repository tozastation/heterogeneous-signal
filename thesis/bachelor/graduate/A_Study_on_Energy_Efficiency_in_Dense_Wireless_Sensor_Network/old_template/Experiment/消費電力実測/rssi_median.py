import json
import statistics

filepath = '000b78fffe052ce9_20191128_200712.log'
rssis = []
with open(filepath) as fp:
    lines = fp.readlines()
    for line in lines: 
        buf = line.strip("lora/tarako_chan/000b78fffe052ce9/rx")
        bufDict = json.loads(buf)
        rssi = int(bufDict["gw"][0]["rssi"])
        rssis.append(rssi)

median = statistics.median(rssis)
ave = statistics.mean(rssis)
print("average:" + str(ave))
print("median:" + str(median))

# 中央値: -114.0