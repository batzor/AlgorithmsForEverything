use std::io::prelude::*;

struct Seat {
    row: usize,
    col: usize,
    sid: usize,
}

impl Seat {
    fn new(row: usize, col: usize) -> Self {
        Seat {
            row: row,
            col: col,
            sid: row * 8 + col,
        }
    }

    fn from_ticket(ticket: String) -> Self {
        let binstring: String = ticket
            .as_str()
            .replace("F", "0")
            .replace("B", "1")
            .replace("R", "1")
            .replace("L", "0");
        let seatstr = binstring.split_at(7);

        Seat::new(
            usize::from_str_radix(seatstr.0, 2).unwrap(),
            usize::from_str_radix(seatstr.1, 2).unwrap(),
        )
    }
}

fn part1(seats: &[Seat]) -> usize {
    return seats[seats.len() - 1].sid;
}

fn part2(seats: &[Seat]) -> usize {
    let mut prev_sid: usize = seats[0].sid;
    for i in 1..seats.len() - 1 {
        if prev_sid + 2 == seats[i].sid {
            return prev_sid + 1;
        }
        prev_sid = seats[i].sid;
    }
    panic!("Seat not found");
}

fn main() -> std::io::Result<()> {
    let input = std::fs::File::open("input")?;
    let reader = std::io::BufReader::new(input);

    let mut seats: Vec<Seat> = Vec::new();
    for line in reader.lines() {
        seats.push(Seat::from_ticket(line?));
    }

    seats.sort_by(|a, b| a.sid.cmp(&b.sid));

    println!("Part 1: {}", part1(&seats));
    println!("Part 2: {}", part2(&seats));
    Ok(())
}
