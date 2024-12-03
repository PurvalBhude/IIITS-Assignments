/**
 * Name: Purval Madhukar Bhude
 * Roll No. S20230010193
 * Assignment 11 Question 1
 */

import java.util.*;

class SongTrack {
    private String musicTitle;
    private String musicArtist;
    private String musicGenre;
    private int trackDuration;

    public SongTrack(String musicTitle, String musicArtist, String musicGenre, int trackDuration) {
        this.musicTitle = musicTitle;
        this.musicArtist = musicArtist;
        this.musicGenre = musicGenre;
        this.trackDuration = trackDuration;
    }

    public String getMusicTitle() { return musicTitle; }
    public String getMusicArtist() { return musicArtist; }
    public String getMusicGenre() { return musicGenre; }
    public int getTrackDuration() { return trackDuration; }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        SongTrack other = (SongTrack) obj;
        return musicTitle.equals(other.musicTitle) && 
               musicArtist.equals(other.musicArtist);
    }

    @Override
    public int hashCode() {
        return Objects.hash(musicTitle, musicArtist);
    }

    @Override
    public String toString() {
        return String.format("Title: %s, Artist: %s, Genre: %s, Duration: %d seconds",
                musicTitle, musicArtist, musicGenre, trackDuration);
    }
}

class MusicPlaylist {
    private Set<SongTrack> playlistTracks;

    public MusicPlaylist() {
        this.playlistTracks = new HashSet<>();
    }

    public boolean addTrackToPlaylist(SongTrack newTrack) {
        return playlistTracks.add(newTrack);
    }

    public boolean removeTrackFromPlaylist(String trackTitle) {
        boolean trackFound = false;
        Iterator<SongTrack> trackIterator = playlistTracks.iterator();
        
        while (trackIterator.hasNext()) {
            SongTrack currentTrack = trackIterator.next();
            if (currentTrack.getMusicTitle().equals(trackTitle)) {
                trackIterator.remove();
                trackFound = true;
                break;
            }
        }
        return trackFound;
    }

    public List<SongTrack> getTracksByGenre(String targetGenre) {
        List<SongTrack> genreTracks = new ArrayList<>();
        Iterator<SongTrack> trackIterator = playlistTracks.iterator();
        
        while (trackIterator.hasNext()) {
            SongTrack currentTrack = trackIterator.next();
            if (currentTrack.getMusicGenre().equals(targetGenre)) {
                genreTracks.add(currentTrack);
            }
        }

        genreTracks.sort((t1, t2) -> t1.getMusicTitle().compareTo(t2.getMusicTitle()));
        return genreTracks;
    }

    public int calculateTotalDuration() {
        int totalSeconds = 0;
        Iterator<SongTrack> trackIterator = playlistTracks.iterator();
        
        while (trackIterator.hasNext()) {
            totalSeconds += trackIterator.next().getTrackDuration();
        }
        return totalSeconds;
    }

    public List<SongTrack> getTopNLongestTracks(int numberOfTracks) {
        List<SongTrack> allTracks = new ArrayList<>(playlistTracks);
        
        // Sort by duration in descending order
        allTracks.sort((t1, t2) -> Integer.compare(t2.getTrackDuration(), t1.getTrackDuration()));
        
        // Return either N tracks or all tracks if fewer than N
        int resultSize = Math.min(numberOfTracks, allTracks.size());
        return allTracks.subList(0, resultSize);
    }
}

// Main class to demonstrate functionality
public class Q1_S20230010193 {
    public static void main(String[] args) {
        MusicPlaylist myPlaylist = new MusicPlaylist();

        // Adding sample songs
        myPlaylist.addTrackToPlaylist(new SongTrack("SANTA BAI", "SANTA", "Rock", 354));
        myPlaylist.addTrackToPlaylist(new SongTrack("TAMBDI CHAMDI", "MARATHI BOYZ", "Rock", 482));
        myPlaylist.addTrackToPlaylist(new SongTrack("Shape of You", "Ed Sheeran", "Pop", 234));
        myPlaylist.addTrackToPlaylist(new SongTrack("Thriller", "Michael Jackson", "Pop", 357));

        // Test duplicate song (should not be added)
        System.out.println("Adding duplicate song: " + 
            myPlaylist.addTrackToPlaylist(new SongTrack("Thriller", "Michael Jackson", "Pop", 357)));

        // Get all Pop songs
        System.out.println("\nPop songs:");
        List<SongTrack> popSongs = myPlaylist.getTracksByGenre("Pop");
        popSongs.forEach(System.out::println);

        // Get total duration
        System.out.println("\nTotal playlist duration: " + 
            myPlaylist.calculateTotalDuration() + " seconds");

        // Get top 3 longest songs
        System.out.println("\nTop 3 longest songs:");
        List<SongTrack> longestTracks = myPlaylist.getTopNLongestTracks(3);
        longestTracks.forEach(System.out::println);

        // Remove a song
        System.out.println("\nRemoving 'Thriller'");
        myPlaylist.removeTrackFromPlaylist("Thriller");

        // Show updated Pop songs
        System.out.println("\nUpdated Pop songs:");
        popSongs = myPlaylist.getTracksByGenre("Pop");
        popSongs.forEach(System.out::println);
    }
}

class BasicCalculator {
    public double add(double number1, double number2) {
        return number1 + number2;
    }
    public double subtract(double number1, double number2) {
        return number1 - number2;
    }
    public double multiply(double number1, double number2) {
        return number1 * number2;
    }
    public double divide(double number1, double number2) {
        if (number2 == 0) {
            System.out.println("Error: Division by zero is undefined.");
            return 0;
        }
        return number1 / number2;
    }
}