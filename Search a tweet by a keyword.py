#!/usr/bin/env python
# coding: utf-8

# In[10]:


def write_tweet_tofile(tweet):
    file1 = open("chemo-tweets.txt","a+")  
    file1.writelines(tweet) 
    file1.close()


# In[17]:

# sample-50-tweets.txt
# twitter-data

f = open("twitter-data.txt", "r")
count=0
found=-1
for line in f:

    if not line.startswith("@"):
        ' '.join(line)
#         print("Number of matches found ==> " + line)
    else:   
        found = line.lower().find("chemo ")     
        if found >= 0:
            count += 1            
            print("FULL Tweet => " + str(line))
            write_tweet_tofile(line.lower())
    
    
    


# In[ ]:





# In[ ]:




