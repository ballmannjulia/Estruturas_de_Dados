#include "../include/hours.hpp"

Hours::Hours() : hours{0}, minutes{0}, seconds{0} {}

Hours::Hours(int h, int m, int s) : hours{h}, minutes{m}, seconds{s} {
    normalize();
}

void Hours::set_time(int h, int m, int s) {
    hours = h;
    minutes = m;
    seconds = s;
    normalize();
}

int Hours::get_hours() const { 
    return hours; 
}

int Hours::get_minutes() const { 
    return minutes; 
}

int Hours::get_seconds() const { 
    return seconds; 
}

int Hours::to_seconds() const {
    return seconds + 60 * minutes + 3600 * hours;
}

double Hours::to_hours() const {
    return to_seconds() / 3600.0;
}

double Hours::to_minutes() const {
    return to_seconds() / 60.0;
}

std::string Hours::to_string() const {
    return (hours < 10 ? "0" + std::to_string(hours) : std::to_string(hours))
           + ":" +
           (minutes < 10 ? "0" + std::to_string(minutes) : std::to_string(minutes))
           + ":" +
           (seconds < 10 ? "0" + std::to_string(seconds) : std::to_string(seconds));
}

bool Hours::operator==(const Hours& other) const {
    return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
}

bool Hours::operator!=(const Hours& other) const {
    return !(*this == other);
}   

bool Hours::operator>(const Hours& other) const {
    if(hours > other.get_hours()) {
        return true;
    }
    else if(hours < other.get_hours()) {
        return false;
    }
    else if(minutes > other.get_minutes()) {
        return true;
    }
    else if(minutes < other.get_minutes()) {
        return false;
    }
    else if(seconds > other.get_seconds()) {
        return true;
    }
    return false;
}

bool Hours::operator>=(const Hours& other) const {
    return *this > other || *this == other;
}   

bool Hours::operator<(const Hours& other) const {
    return !(*this >= other);
}

bool Hours::operator<=(const Hours& other) const {
    return !(*this > other);
}

Hours Hours::operator+(const Hours& other) const {
    return Hours(hours + other.get_hours(), 
                minutes + other.get_minutes(), 
                seconds + other.get_seconds());
}

// In the operator- function:
Hours Hours::operator-(const Hours& other) const {
    return Hours(0, 0, to_seconds() - other.to_seconds());
}


void Hours::normalize() {
    int add_min = seconds / 60;
    seconds = seconds % 60;
    minutes += add_min;
    int add_h = minutes / 60;
    minutes = minutes % 60;
    hours += add_h;
}
