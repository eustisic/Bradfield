const BILLION = 1000000000;
const CLOCKS_PER_SEC = 1000000;

const fetchDecodeExecute = () => {
  const start = Date.now();

  for (let i = 0; i < BILLION; i++) {
    let a = i * i;
  }

  let secs = (Date.now() - start) / CLOCKS_PER_SEC;

  let ops = BILLION / secs;

  console.log(
    `Clock speed approx. ${(ops / BILLION).toLocaleString(undefined, {
      minimumFractionDigits: 3,
    })} GHz`
  );
};

fetchDecodeExecute();
