function mergeLists() {
  const input1 = document.getElementById("list1").value.trim();
  const input2 = document.getElementById("list2").value.trim();

  if (!input1 || !input2) {
    alert("Please enter both lists.");
    return;
  }

  const arr1 = input1.split(",").map(Number);
  const arr2 = input2.split(",").map(Number);

  const merged = [];
  let i = 0, j = 0;

  while (i < arr1.length && j < arr2.length) {
    if (arr1[i] < arr2[j]) {
      merged.push(arr1[i++]);
    } else {
      merged.push(arr2[j++]);
    }
  }

  while (i < arr1.length) merged.push(arr1[i++]);
  while (j < arr2.length) merged.push(arr2[j++]);

  document.getElementById("output").innerText = merged.join(", ");
}
