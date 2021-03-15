use std::io::prelude::*;

struct Forest {
    tree_map: Vec<Vec<bool>>,
    depth: usize,
    width: usize,
}

impl Forest {
    fn lookup(&self, row: usize, col: usize) -> Result<bool, &'static str> {
        let wrapped_col = col % self.width;
        if row >= self.depth {
            Err("too deep!")
        } else {
            Ok(self.tree_map[row][wrapped_col])
        }
    }

    fn check_path(&self, down: usize, right: usize) -> usize {
        let mut row: usize = 0;
        let mut col: usize = 0;
        let mut count: usize = 0;
        loop {
            match &self.lookup(row, col) {
                Ok(is_tree) => {
                    if *is_tree {
                        count += 1;
                    }
                    row += down;
                    col += right;
                }
                Err(_) => {
                    break;
                }
            }
        }

        return count;
    }
}

fn main() -> std::io::Result<()> {
    let input = std::fs::File::open("input")?;
    let reader = std::io::BufReader::new(input);
    let mut tree_map: Vec<Vec<bool>> = Vec::new();

    for line in reader.lines() {
        tree_map.push(line?.chars().map(|c| c == '#').collect());
    }
    let num_row: usize = tree_map.len();
    let num_col: usize = tree_map[0].len();

    let forest: Forest = Forest {
        tree_map: tree_map,
        depth: num_row,
        width: num_col,
    };

    println!("Part 1: {}", forest.check_path(1, 3));

    let mut part2: usize = forest.check_path(1, 1);
    part2 *= forest.check_path(1, 3);
    part2 *= forest.check_path(1, 5);
    part2 *= forest.check_path(1, 7);
    part2 *= forest.check_path(2, 1);
    println!("Part 2: {}", part2);
    Ok(())
}
