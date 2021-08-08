use std::io;

pub fn diff(a: Vec<u16>, b: Vec<u16>) -> Vec<u16> {
    a.iter()
        .filter( |&incoming| !b.contains(incoming))
        .cloned()
        .collect()
}

fn main() -> Result<(), io::Error> {
    let aa = vec!(11,22,33,44,55);
    let bb = vec!(11,22,31,40,55);

    println!("{:?}", diff(aa, bb));

    Ok(())
}
