let weather = Document.getElementById("weather");

let weather_integer;

if (weather.value === 'Clear') {
    weather_integer = 0;
} else if (weather.value === 'Cloudy') {
    weather_integer = 1;
} else if (weather.value === 'Dust Storm') {
    weather_integer = 2;
} else if (weather.value === 'Fine') {
    weather_integer = 3;
} else if (weather.value === 'Flooding of Slipways/Rivulets') {
    weather_integer = 4;
} else if (weather.value === 'Fog / Mist') {
    weather_integer = 5;
} else if (weather.value === 'Hail or Sleet') {
    weather_integer = 6;
} else if (weather.value === 'Heavy Rain') {
    weather_integer = 7;
} else if (weather.value === 'Light Rain') {
    weather_integer = 8;
} else if (weather.value === 'Mist or Fog') {
    weather_integer = 9;
} else if (weather.value === 'Others') {
    weather_integer = 10;
} else if (weather.value === 'Snow') {
    weather_integer = 11;
} else if (weather.value === 'Strong Wind') {
    weather_integer = 12;
} else if (weather.value === 'Very Cold') {
    weather_integer = 13;
} else if (weather.value === 'Very Hot') {
    weather_integer = 14;
} else if (weather.value === 'Wind') {
    weather_integer = 15;
}

let district = Document.getElementById("district");

let district_integer;

if (district.value === 'Bagalkot') {
    district_integer = 0;
} else if (district.value === 'Ballari (Bellary)') {
    district_integer = 1;
} else if (district.value === 'Belagavi City (Belgaum)') {
    district_integer = 2;
} else if (district.value === 'Belagavi Dist (Belgaum)') {
    district_integer = 3;
} else if (district.value === 'Bengaluru City') {
    district_integer = 4;
} else if (district.value === 'Bengaluru Dist') {
    district_integer = 5;
} else if (district.value === 'Bidar') {
    district_integer = 6;
} else if (district.value === 'Chamarajanagar') {
    district_integer = 7;
} else if (district.value === 'Chickballapura (Chikkaballapur)') {
    district_integer = 8;
} else if (district.value === 'Chikkamagaluru (Chikmagalur)') {
    district_integer = 9;
} else if (district.value === 'Chitradurga') {
    district_integer = 10;
} else if (district.value === 'Dakshina Kannada') {
    district_integer = 11;
} else if (district.value === 'Davanagere') {
    district_integer = 12;
} else if (district.value === 'Dharwad') {
    district_integer = 13;
} else if (district.value === 'Gadag') {
    district_integer = 14;
} else if (district.value === 'Hassan') {
    district_integer = 15;
} else if (district.value === 'Haveri') {
    district_integer = 16;
} else if (district.value === 'Hubballi Dharwad City') {
    district_integer = 17;
} else if (district.value === 'K.G.F') {
    district_integer = 18;
} else if (district.value === 'Kalaburagi (Gulbarga)') {
    district_integer = 19;
} else if (district.value === 'Kalaburagi City (Gulbarga)') {
    district_integer = 20;
} else if (district.value === 'Karnataka Railways') {
    district_integer = 21;
} else if (district.value === 'Kodagu (Coorg)') {
    district_integer = 22;
} else if (district.value === 'Kolar') {
    district_integer = 23;
} else if (district.value === 'Koppal') {
    district_integer = 24;
} else if (district.value === 'Mandya') {
    district_integer = 25;
} else if (district.value === 'Mangaluru City') {
    district_integer = 26;
} else if (district.value === 'Mysuru City (Mysore)') {
    district_integer = 27;
} else if (district.value === 'Mysuru Dist (Mysore)') {
    district_integer = 28;
} else if (district.value === 'Raichur') {
    district_integer = 29;
} else if (district.value === 'Ramanagara') {
    district_integer = 30;
} else if (district.value === 'Shivamogga (Shimoga)') {
    district_integer = 31;
} else if (district.value === 'Tumakuru (Tumkur)') {
    district_integer = 32;
} else if (district.value === 'Udupi') {
    district_integer = 33;
} else if (district.value === 'Uttara Kannada (Karwar)') {
    district_integer = 34;
} else if (district.value === 'Vijayanagara') {
    district_integer = 35;
} else if (district.value === 'Vijayapur (Bijapur)') {
    district_integer = 36;
} else if (district.value === 'Yadgir') {
    district_integer = 37;
}