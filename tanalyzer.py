#!/usr/bin/env python
# coding: utf-8


from nltk.corpus import webtext
from nltk.collocations import BigramCollocationFinder
from nltk.metrics import BigramAssocMeasures
from nltk.corpus import stopwords


def tanalyzer():
    print("Hello, Twitter Mining Module!")
    
    
# helper function that splits a user-tweet line 
#  into items of a tuple and returns the tuple
def get_user_tweet_tuple(user_tweet_text_line):   
    list = user_tweet_text_line.split("|")  
    if  len(list) == 2:
        user_tweet_tuple = (list[0], list[1])  
        return user_tweet_tuple        
    else:
        return None

def is_hashtag(word):
    if word.startswith("#"):
        return True
    else:
        return False
    
# loading the facebook sentiment file into a list
def load_fb_sentiments(sentiment_file):
    sentiments = []
    f = open(sentiment_file, "r")
    for line in f:        
        sentiments.append(" "+line.rstrip() +" ")
    return sentiments
    


    
# This function takes an input file full of tweets
# and search it for the keyword that is also 
# provided in the parameter list
# it returns the the list of relevant tweets 
#   that match the passed keyword
def set_search_context(file_name, keyword_list):
    relevant_tweets = []
    user_tweet_tuple = ()
    f = open(file_name, "r")
    for line in f:            
        user_tweet_tuple = get_user_tweet_tuple(line)
        # print(type(user_tweet_tuple))
        # print("user-tweet-tuple => ", user_tweet_tuple)
        if user_tweet_tuple is not None:
            words = user_tweet_tuple[1].lower().split()
            for keyword in keyword_list:
                if keyword in words:

                    relevant_user_tweet_tuple = (user_tweet_tuple[0],user_tweet_tuple[1])

                    relevant_tweets.append(relevant_user_tweet_tuple)                                  
    return relevant_tweets

                

#  This function takes a tweet file to analyze and 
#  and the number of bgrams to extract as two params
# usign the NLTK python library, we can perform this 
# it returns the number of bigrams matcging
def extract_bigrams(file_toanalyze, word_length, num_of_bigrams):
    # get the list of words from the file 
    words_list = [word.lower() for word in webtext.words(file_toanalyze)]
    
    # construct a finder object to find the best bigrams
    finder = BigramCollocationFinder.from_words(words_list)
    
    
    # create a noise filtering handler
    noise_handler = filter_word_noise(word_length)
    
    # apply the noise filtering handler 
    finder.apply_word_filter(noise_handler)    

    # actually find the desired number of bigrams 
    list_of_bigrams= finder.nbest(BigramAssocMeasures.likelihood_ratio, num_of_bigrams)
    
    # return the list of bigrams
    return list_of_bigrams          
    
    
def filter_word_noise (word_length):    
    # remove the stop word in the English dictionary
    ignored_words = set(stopwords.words('english'))

    # creating a filter object and setting it up with 
    # removing the noise that is less that 4 characters
    # or any word that happens to be in the stopwords list
    noise_filter_handler = lambda ignored_word: len(ignored_word) < word_length or ignored_word in ignored_words
    return noise_filter_handler
    
    
# This function designed to search for a given bigram in a tweet
#  The first param is the actual tweet text and the second if 
# the bigram 
def is_bigram_intweet(tweet, bigram) :
    bigram_text = bigram[0] + " " + bigram[1]
    if tweet.find(bigram_text) > 0:
        return True
    
# This function takes a list of relevant tweets and a list of bigrams
# then it construct tuples of user handles and bigram to make it ready
# for constructing a bipartine network 
def construct_user_bigram_list(relevant_user_tweets, bigrams_list):
    user_bigram_list = []
    for tweet in relevant_user_tweets:
        for bigram in bigrams_list:
            bigram_found = is_bigram_intweet(tweet[1], bigram)
            # print("is bigram found? ==> " + str(bigram_found))
            if bigram_found:
                bigram_text = bigram[0] + " " + bigram[1]
                user_bigram_list.append((tweet[0], bigram_text))
    # print("user-bigram-populated ==> " + str(user_bigram_list))
    return user_bigram_list
    
   
# if a sentiment exists 
def sentiment_exits(tweet, sentiments_list) :    
    for sentiment in sentiments_list:
        # print("Current sentiment is ==> " + sentiment + "Current tweets is: ==> " + tweet)
        if tweet.find(sentiment) > 0:
            # print("Sentiment found is" + sentiment)
            return sentiment
                
# construct a list of tuples of (user,sentiment)
def construct_user_sentiment_list(relevant_user_tweets, sentiments_list):
    user_sentiment_list = []
    for tweet in relevant_user_tweets:
        sentiment = sentiment_exits(tweet[1], sentiments_list)
        # print("sentiment is: " + str(sentiment))
        if sentiment is not None:
            user_sentiment_list.append((tweet[0], sentiment))
            # print("(user, sentiment) tuple is" + str((tweet[0], sentiment)))
    return user_sentiment_list    
    
def construct_user_hashtag_list(relevant_user_tweets):
    user_hashtag_list = []
    for tweet in relevant_user_tweets:
        words = tweet[1].split()
        for word in words:
            if is_hashtag(word):
                user_hashtag_list.append((tweet[0], word)) 
    return user_hashtag_list       
    
          