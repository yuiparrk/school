from A1sub import getTopSongsInfo
import pprint

top_songs = getTopSongsInfo('top_spotify_songs_USA_earlyOct24.csv')
pprint.pprint(top_songs, width=100)