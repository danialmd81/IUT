CREATE DATABASE Spotify;

USE Spotify;

CREATE TABLE Users (
    UserID INT PRIMARY KEY auto_increment,
    username VARCHAR(255) NOT NULL,
    password VARCHAR(255) NOT NULL,
    Email VARCHAR(255) UNIQUE NOT NULL,
    birthday DATE NOT NULL,
    address VARCHAR(255),
    wallet DECIMAL(10, 2) DEFAULT 0.00,
    is_premium BOOLEAN DEFAULT FALSE
);

CREATE TABLE PremiumUsers (
    PremiumID INT PRIMARY KEY,
    FOREIGN KEY (PremiumID) REFERENCES Users (UserID) on DELETE CASCADE
);

CREATE TABLE Artist (
    ArtistID INT PRIMARY KEY,
    name VARCHAR(255),
    FOREIGN KEY (ArtistID) REFERENCES Users (UserID) on DELETE CASCADE
);

CREATE TABLE Album (
    Title VARCHAR(255) PRIMARY KEY,
    ArtistID INT,
    genre VARCHAR(255),
    country VARCHAR(255),
    age INT,
    FOREIGN KEY (ArtistID) REFERENCES Artist (ArtistID) ON DELETE CASCADE
);

CREATE TABLE Songs (
    SongID INT PRIMARY KEY auto_increment,
    name VARCHAR(255) NOT NULL,
    ArtistID INT,
    Album_Title VARCHAR(255),
    genre VARCHAR(255) NOT NULL,
    country VARCHAR(255) NOT NULL,
    age VARCHAR(255) NOT NULL,
    lyric VARCHAR(1024) NOT NULL,
    is_limited BOOLEAN DEFAULT FALSE,
    audio_file LONGBLOB,
    Foreign Key (ArtistID) REFERENCES Artist (ArtistID) on DELETE CASCADE,
    Foreign Key (Album_Title) REFERENCES Album (Title) on DELETE CASCADE
);

CREATE TABLE Playlists (
    PlaylistID INT PRIMARY KEY auto_increment,
    PremiumID INT,
    name VARCHAR(255) NOT NULL,
    isPrivate BOOLEAN DEFAULT FALSE,
    FOREIGN KEY (PremiumID) REFERENCES PremiumUsers (PremiumID) on DELETE CASCADE
);

CREATE TABLE Playlist_Songs (
    PID INT,
    SID INT,
    PRIMARY KEY (PID, SID),
    Foreign Key (PID) REFERENCES Playlists (PlaylistID) on DELETE CASCADE,
    Foreign Key (SID) REFERENCES Songs (SongID) on DELETE CASCADE
);

CREATE Table Concert (
    ConcertID INT PRIMARY KEY auto_increment,
    ArtistID INT,
    Price INT,
    Foreign Key (ArtistID) REFERENCES Artist (ArtistID) ON DELETE CASCADE
);

CREATE TABLE Concert_Ticket (
    TicketID INT PRIMARY KEY auto_increment,
    ConcertID INT,
    isValid BOOLEAN,
    Foreign Key (ConcertID) REFERENCES Concert (ConcertID) on DELETE CASCADE
);

CREATE TABLE User_Ticket (
    PrID INT,
    TID INT,
    PRIMARY KEY (PrID, TID),
    Foreign Key (PrID) REFERENCES PremiumUsers (PremiumID) on DELETE CASCADE,
    Foreign Key (TID) REFERENCES Concert_Ticket (TicketID) on DELETE CASCADE
);

CREATE TABLE Friends (
    PremiumID INT,
    FriendID INT,
    PRIMARY KEY (PremiumID, FriendID),
    FOREIGN KEY (FriendID) REFERENCES PremiumUsers (PremiumID),
    FOREIGN KEY (PremiumID) REFERENCES PremiumUsers (PremiumID) on DELETE CASCADE
);

CREATE TABLE Followers (
    PremiumID INT,
    FollowerID INT,
    PRIMARY KEY (PremiumID, FollowerID),
    FOREIGN KEY (FollowerID) REFERENCES PremiumUsers (PremiumID),
    FOREIGN KEY (PremiumID) REFERENCES PremiumUsers (PremiumID) on DELETE CASCADE
);

CREATE Table Comments (
    ID INT PRIMARY KEY auto_increment,
    PrID INT,
    PID INT,
    SID INT,
    AID INT,
    Comment VARCHAR(1024),
    Foreign Key (PrID) REFERENCES PremiumUsers (PremiumID) on DELETE CASCADE,
    Foreign Key (PID) REFERENCES Playlists (PlaylistID) on DELETE CASCADE,
    Foreign Key (SID) REFERENCES Songs (SongID) on DELETE CASCADE,
    Foreign Key (AID) REFERENCES Artist (ArtistID) on DELETE CASCADE
);

CREATE Table Likes (
    ID INT PRIMARY KEY auto_increment,
    PrID INT,
    PID INT,
    SID INT,
    AID INT,
    Foreign Key (PrID) REFERENCES PremiumUsers (PremiumID) on DELETE CASCADE,
    Foreign Key (PID) REFERENCES Playlists (PlaylistID) on DELETE CASCADE,
    Foreign Key (SID) REFERENCES Songs (SongID) on DELETE CASCADE,
    Foreign Key (AID) REFERENCES Artist (ArtistID) on DELETE CASCADE
);

CREATE Table Favorite (
    ID INT PRIMARY KEY auto_increment,
    PrID INT,
    PID INT,
    SID INT,
    AID INT,
    Foreign Key (PrID) REFERENCES PremiumUsers (PremiumID) on DELETE CASCADE,
    Foreign Key (PID) REFERENCES Playlists (PlaylistID) on DELETE CASCADE,
    Foreign Key (SID) REFERENCES Songs (SongID) on DELETE CASCADE,
    Foreign Key (AID) REFERENCES Artist (ArtistID) on DELETE CASCADE
);

CREATE Table Favorite_Artist (
    PrID INT,
    ArID INT,
    PRIMARY KEY (PrID, ArID),
    Foreign Key (PrID) REFERENCES PremiumUsers (PremiumID) on DELETE CASCADE,
    Foreign Key (ArID) REFERENCES Artist (ArtistID) on DELETE CASCADE
);