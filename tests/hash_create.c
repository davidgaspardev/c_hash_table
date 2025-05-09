#include <stdio.h>
#include <hash.h>
#include <cbytes.h>

const char* hash_inputs[150];

int main() {

    unsigned int hash_inputs_len = sizeof(hash_inputs)/sizeof(*hash_inputs);

    printf("[ TEST ] %d hash inputs to test\n", hash_inputs_len);

    int limit = 0xFF;

    byte_t result[limit];
    for (int i = 0; i < limit; i++) result[i] = 0;

    for (int i = 0; i < hash_inputs_len; i++) {
        for (int j = 0; j < hash_inputs_len; j++) {
            if (equal(hash_inputs[i], hash_inputs[j]) && i != j) {
                printf("[ ERR ] input repeated: %s - %s\n", hash_inputs[i], hash_inputs[j]);
                return 1;
            }
        }
    }

    for (int i = 0; i < hash_inputs_len; i++) {
        unsigned int hash_result = hash(hash_inputs[i], limit);
        result[hash_result]++;
    }

    byte_t collision_count = 0;

    for (int i = 0; i < limit; i++) {
        if (result[i] > 1) {
            collision_count += result[i];
            printf("[ TEST ] Collision to: %d hash (%d)\n", i, result[i]);
        }
    }

    float collision_tax = ((float) collision_count / hash_inputs_len) * 100;

    printf("[ TEST ] %d collisions (%f%%)\n", collision_count, collision_tax);

    if (collision_tax > /* tolerance of up to 46% */ 46) return 1;

    return 0;
}

const char* hash_inputs[] = {
    "David Gaspar",
    "Hello, world!",
    "1234567890",
    "abcdefghijklmnopqrstuvwxyz",
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
    " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~",
    "The quick brown fox jumps over the lazy dog",
    "A bird in the hand is worth two in the bush",
    "Actions speak louder than words",
    "An apple a day keeps the doctor away",
    "As you sow, so shall you reap",
    "Beauty is in the eye of the beholder",
    "Better late than never",
    "Don't count your chickens before they hatch",
    "Every cloud has a silver lining",
    "Familiarity breeds contempt",
    "Fortune favors the bold",
    "Honesty is the best policy",
    "If at first you don't succeed, try, try again",
    "Laughter is the best medicine",
    "Money doesn't grow on trees",
    "Necessity is the mother of invention",
    "No pain, no gain",
    "One man's trash is another man's treasure",
    "Patience is a virtue",
    "Practice makes perfect",
    "Rome wasn't built in a day",
    "The early bird catches the worm",
    "You can't judge a book by its cover",
    "",
    "a",
    "aa",
    "aaa",
    "aaaa",
    "aaaaa",
    "aaaaaa",
    "aaaaaaa",
    "aaaaaaaa",
    "aaaaaaaaa",
    "aaaaaaaaaa",
    "apple",
    "banana",
    "cherry",
    "date",
    "elderberry",
    "fig",
    "grape",
    "honeydew",
    "iota",
    "jackfruit",
    "kiwi",
    "lemon",
    "mango",
    "nectarine",
    "orange",
    "pear",
    "quince",
    "raspberry",
    "strawberry",
    "tangerine",
    "ugli fruit",
    "vanilla bean",
    "watermelon",
    "yellow squash",
    "zucchini",
    "ant",
    "bat",
    "cat",
    "dog",
    "elephant",
    "frog",
    "goat",
    "hippopotamus",
    "iguana",
    "jaguar",
    "kangaroo",
    "llama",
    "monkey",
    "newt",
    "octopus",
    "penguin",
    "quail",
    "raccoon",
    "squirrel",
    "turtle",
    "urchin",
    "vulture",
    "whale",
    "xylophone",
    "yak",
    "zebra",
    "wKz!P@U5c6g$8mHj",
    "9yXv?L^fIa=qo#b",
    "&E*rY7sxZt~NhpJ",
    "2B1iGnMl3O%pFQd",
    "7D4uTqoV^m#l@",
    "#P!kS$8uRgNfCwHb",
    "zYyF0hLc*X9i6tE",
    "*1QgV7K#zjZdU",
    "WxL^fIa=qo#b",
    "@rY7sxZt~NhpJ",
    "3iGnMl3O%pFQd",
    "6D4uTqoV^m#l@",
    "9kS$8uRgNfCwHb",
    "cYyF0hLc*X9i6tE",
    "5QgV7K#zjZdU",
    "nI2@U5c6g$8mHj",
    "xL^fIa=qo#b",
    "4uTqoV^m#l@",
    "kS$8uRgNfCwHb",
    "yF0hLc*X9i6tE",
    "7K#zjZdU",
    "1iGnMl3O%pFQd",
    "pocket",      
    "agile",       
    "coherent",    
    "glow",        
    "quiver",      
    "fragmented",  
    "spontaneous", 
    "glimmer",     
    "looming",     
    "maverick",    
    "embrace",     
    "paragon",     
    "shackles",    
    "perpetuate",  
    "flimsy",      
    "exodus",      
    "skyscraper",  
    "vigilant",    
    "eclipse",     
    "dizzy",       
    "confetti",    
    "intrepid",    
    "relish",      
    "turbulent",   
    "influx",      
    "arduous",     
    "discrepancy", 
    "cosmic",      
    "abundance",   
    "glisten",     
    "intermittent",
    "whirlwind",   
    "vortex",      
    "glacier",     
    "quicksilver",
    "Elon Musk",
    "Dennis Ritchie"
};
