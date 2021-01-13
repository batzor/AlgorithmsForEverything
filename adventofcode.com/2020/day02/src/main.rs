use std::error::Error;
use std::str::{self, FromStr};

use lazy_static::lazy_static;
use regex::Regex;

struct Entry {
    min: usize,
    max: usize,
    letter: char,
    word: String,
}

macro_rules! err {
    ($($tt:tt)*) => { Err(Box::<dyn Error>::from(format!($($tt)*))) }
}

impl FromStr for Entry {
    type Err = Box<dyn Error>;

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        lazy_static! {
            static ref RE: Regex =
                Regex::new(r"(?P<min>[0-9]+)\-(?P<max>[0-9]+) (?P<letter>\w): (?P<word>\w+)")
                    .unwrap();
        }

        let caps = match RE.captures(s) {
            None => return err!("did not match the regex"),
            Some(caps) => caps,
        };

        return Ok(Entry {
            min: caps["min"].parse()?,
            max: caps["max"].parse()?,
            letter: caps["letter"].parse()?,
            word: caps["word"].parse()?,
        });
    }
}

impl Entry {
    fn is_valid_part1(&self) -> bool {
        let count: usize = self.word.chars().filter(|&c| c == self.letter).count();
        return count <= self.max && count >= self.min;
    }

    fn is_valid_part2(&self) -> bool {
        let mut is_valid = false;
        match self.word.chars().nth(self.min - 1) {
            Some(c) => is_valid ^= c == self.letter,
            _ => {}
        };

        match self.word.chars().nth(self.max - 1) {
            Some(c) => is_valid ^= c == self.letter,
            _ => {}
        }

        return is_valid;
    }
}

fn main() {
    let input = std::fs::read_to_string("input").unwrap();
    let mut it = input.lines();
    let mut valid_count_part1 = 0;
    let mut valid_count_part2 = 0;
    loop {
        let line = it.next();
        match line {
            Some(s) => {
                let e: Entry = Entry::from_str(s).unwrap();
                if e.is_valid_part1() {
                    valid_count_part1 += 1;
                };
                if e.is_valid_part2() {
                    valid_count_part2 += 1;
                };
            }
            None => break,
        }
    }
    println!("Part 1: {}", valid_count_part1);
    println!("Part 2: {}", valid_count_part2);
}
