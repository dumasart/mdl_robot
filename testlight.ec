node testlight
  (b: bool;
  c1: int;
  c2: int)
returns
  (val: int;
  state: bool);

var
  V7_w_000: bool;

let
  val = (if state then c1 else c2);
  state = (b <> V7_w_000);
  V7_w_000 = (false -> (pre state));
tel

