import subprocess
import pandas as pd
import matplotlib.pyplot as plt
sort=["insertion","selection","merge","quick","heap","radix","shell"]
sizes=[i for i in range(0,500000,20000)]
time=[]
for size in sizes:
    subtime=[]
    for algo in sort:
        f=open("in.txt","w")
        f.writelines(str(size))
        f.close()
        a=f".\{algo}.exe"
        process=subprocess.run(a,shell=True,capture_output=True)
        b=process.stdout.decode()
        subtime.append(float(b))
        print(f"{algo} {size} {b}")
    time.append(subtime)
df=pd.DataFrame(time,columns=sort,index=sizes)
df.to_csv("ans.csv")
plt.plot(df,label=df.columns.values)
plt.show()