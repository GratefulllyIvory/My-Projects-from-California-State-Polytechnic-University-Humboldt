#!/usr/bin/env python
# coding: utf-8

# In[19]:


import nltk as tk
import networkx as nx
from nltk.metrics import BigramAssocMeasures
from nltk.collocations import BigramCollocationFinder
from nltk.corpus import stopwords
from networkx.algorithms import bipartite
from networkx.algorithms import isomorphism

sample_tweets = ['@cnewb07 | #hermanmiller is looking for an #account #development manager (geiger) in #dallastexasunitedstates, apply now! #job',
          'dcoceancentre | is hiring an #electrician - #direct hire in #ogden, apply now! #job',
          '@diditaihuttu | @diditaihuttu what would your job be or what would you be doing in life if bitcoin would not have existed? #bitcoin #cryptocurrency #jobs\n',
          '@teledevt | @teledevt along with the high number of #job vacancies, the #skills for employees have changed drastically. so here are the skills most in-demand for #techjobs in 2019. #technology',
          '@tv_hiec_chair | rt @mmcgjobs: we are attending the stockport jobs fair on tuesday 24th september.']

sentiments = ['looking', 'attending' , 'doing']


# In[34]:


def create_tuples(tweets):
    tuples = []    
    for tweet in tweets:
        if tweet is not None:
            temp_tuple = tweet.split("|")
            if len(temp_tuple) == 2:
                tuples.append((temp_tuple[0], temp_tuple[1]))
                    
    #print(tuples)
    return tuples

def find_sentiments(tweets, sent):
    usr_sentiment = []
    for current_tweet in tweets:
        words = current_tweet[1].lower().split()
        for curr_sentiment in sent:
            if curr_sentiment in words:
                usr_sentiment.append((current_tweet[0], curr_sentiment))
    return usr_sentiment

def find_hashtag(tweets):
    usr_hashtags = []
    for tweet in tweets:
        hashtags = "" 
        if tweet is not None:
            words = tweet[1].lower().split()
            for word in words:
                if word.startswith("#"):
                    usr_hashtags.append((tweet[0], word))
    return usr_hashtags

def find_mentions(tweets):
    usr_mentions = []
    for tweet in tweets:
        words = tweet[1].lower().split()
        for word in tweet:
            if word.startswith("@"):
                usr_mentions.append((tweet[0], word))
    return usr_mentions

def find_bigrams(tweets):
    
    tweet_text = []
    twitter_bigrams = []

    for tweet in tweets:
        tweet_text = tweet[0] + tweet[1]

        
    #object to operate on list of words
    

    
    finder = BigramCollocationFinder.from_words(tweet_text.split())



    ignored_words = set(stopwords.words('english'))

    filter_stops = lambda ignored_word: len(ignored_word) < 4 or ignored_word in ignored_words

    finder.apply_word_filter(filter_stops)
    
    #number of bigrams
    list_of_bigrams = finder.nbest(BigramAssocMeasures.likelihood_ratio, 20)

    #finds bigrams not in ignored
    
    #print(list_of_bigrams)
    
    for bigram in list_of_bigrams:
        for tweet in tweets:
            bigram_text = bigram[0] + " " + bigram[1]
            if tweet[1].find(bigram_text) > 0:
                twitter_bigrams.append((tweet[0], bigram_text))
    
    return twitter_bigrams

#pass all found tweet tuples as well as a list of sentiments
#calls functions to build lists of tuples for User-Bigram, User-Hashtag, and User-Sentiment graphs
#builds graphs from these functions
def construct_graphs(tuples, sent):

    Bigrams_Graph = nx.Graph()
    Bigrams_Graph.add_edges_from(find_bigrams(tuples))
    #nx.draw(Bigrams_Graph, with_labels = True)
    
    Hashtags_Graph = nx.Graph()
    Hashtags_Graph.add_edges_from(find_hashtag(tuples))
    #nx.draw(Hashtags_Graph, with_labels = True)
    
    Sentiments_Graph = nx.Graph()
    Sentiments_Graph.add_edges_from(find_sentiments(tuples, sent))
    #nx.draw(Sentiments_Graph, with_labels = True)
    
    Mentions_Graph = nx.Graph()
    Mentions_Graph.add_edges_from(find_mentions(tuples))
    #nx.draw(Mentions_Graph, with_labels = True)
    
    print("Created Bigrams Hashtags and Sentiments Graph")
    
    print("Degree centrality for User-Bigrams")
    print("=================")
    deg_cent = nx.degree_centrality(Bigrams_Graph)
    for v in Bigrams_Graph.nodes():
        print("Degree Centrality Node=> {}, Value=> {}".format(v, deg_cent[v]))
    
    print("Degree centrality for User-Hashtags")
    print("=================")
    deg_cent = nx.degree_centrality(Hashtags_Graph)
    for v in Hashtags_Graph.nodes():
        print("Degree Centrality Node=> {}, Value=> {}".format(v, deg_cent[v]))
    
    print("Degree centrality for User-Sentiments")
    print("=================")
    deg_cent = nx.degree_centrality(Sentiments_Graph)
    for v in Sentiments_Graph.nodes():
        print("Degree Centrality Node=> {}, Value=> {}".format(v, deg_cent[v]))
    
    print("Degree centrality for User-Mentions")
    print("=================")
    deg_cent = nx.degree_centrality(Mentions_Graph)
    for v in Mentions_Graph.nodes():
        print("Degree Centrality Node=> {}, Value=> {}".format(v, deg_cent[v]))

#Bipartite Construction

G = nx.path_graph(tuples)

print(bipartite.is_bipartite(G))

nodes= tuples

G = bipartite.weighted_projected_graph(G, nodes, ratio=False)
list(G.nodes())
print(G.edges(data=True))

#IsomorphicComparison
    
G1 = nx.path_graph(tuples)
G2 = nx.path_graph(tuples)
GM = isomorphism.GraphMatcher(G1,G2)
GM.is_isomorphic()


# In[16]:


tuples = create_tuples(sample_tweets)
construct_graphs(tuples, sentiments)


# In[ ]:




