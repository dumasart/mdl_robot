const
  kp_teta : real;
  ki_teta : real;
  T : real;
  pi : real;
  
node Controller
  (Cg: real;
  Cd: real;
  Co_n: real)
returns
  (v_d: real;
  v_g: real);

var
  V11_w_000: bool;
  V12_w_001: bool;
  V14_w_003: bool;
  V15_w_004: bool;
  V16_w_005: bool;
  V17_w_006: bool;
  V18_w_007: bool;
  V19_w_008: bool;
  V20_w_009: bool;
  V21_w_010: bool;
  V24_w_013: real;
  V26_w_015: real;
  V32_w_021: real;
  V34_w_023: real;
  V153_w_000: bool;
  V154_w_002: bool;
  V155_w_004: bool;
  V164_w_000: bool;
  V165_w_001: bool;
  V166_w_005: bool;
  V186_w_000: real;
  V187_w_001: real;
  V188_w_002: real;
  V189_w_007: real;
  V190_w_008: real;
  V191_w_009: real;
  V192_w_010: real;
  V193_w_011: real;
  V194_w_012: real;
  V195_w_013: real;
  V196_w_014: real;
  V197_w_015: real;
  V198_w_016: real;
  V216_w_001: bool;
  V217_w_002: bool;
  V218_w_003: bool;
  V233_w_004: real;

let
  v_d = (if V15_w_004 then -0.500000 else V26_w_015);
  v_g = (if V15_w_004 then 0.500000 else V24_w_013);
  V11_w_000 = (false -> (pre V16_w_005));
  V12_w_001 = (Cd >= 80.000000);
  V14_w_003 = (Co_n < 20.000000);
  V15_w_004 = (V14_w_003 or V165_w_001);
  V16_w_005 = (V17_w_006 and V21_w_010);
  V17_w_006 = (V155_w_004 and V153_w_000);
  V18_w_007 = (V19_w_008 and V20_w_009);
  V19_w_008 = (V217_w_002 and V216_w_001);
  V20_w_009 = (Cd <= 10.000000);
  V21_w_010 = (V12_w_001 and V15_w_004);
  V24_w_013 = (0.500000 * V195_w_013);
  V26_w_015 = (0.500000 * V196_w_014);
  V32_w_021 = ((pi / 200.000000) * V233_w_004);
  V34_w_023 = (Cd + Cg);
  V153_w_000 = (not V11_w_000);
  V154_w_002 = (false -> (pre V17_w_006));
  V155_w_004 = (V18_w_007 or V154_w_002);
  V164_w_000 = (false -> (pre V15_w_004));
  V165_w_001 = (V164_w_000 and V166_w_005);
  V166_w_005 = (not V11_w_000);
  V186_w_000 = (0.000000 -> (pre V187_w_001));
  V187_w_001 = (V188_w_002 + V186_w_000);
  V188_w_002 = (T * V32_w_021);
  V189_w_007 = (V198_w_016 + V197_w_015);
  V190_w_008 = ((-V192_w_010) + V193_w_011);
  V191_w_009 = (2.000000 * V190_w_008);
  V192_w_010 = (if (V194_w_012 < 0.000000) then (-V194_w_012) else V194_w_012);
  V193_w_011 = (0.005000 * V34_w_023);
  V194_w_012 = (2.000000 * V189_w_007);
  V195_w_013 = ((-V189_w_007) + V191_w_009);
  V196_w_014 = (V189_w_007 + V191_w_009);
  V197_w_015 = (kp_teta * V32_w_021);
  V198_w_016 = (ki_teta * V186_w_000);
  V216_w_001 = (not V11_w_000);
  V217_w_002 = (V218_w_003 or V21_w_010);
  V218_w_003 = (false -> (pre V19_w_008));
  V233_w_004 = (Cd - Cg);
tel

