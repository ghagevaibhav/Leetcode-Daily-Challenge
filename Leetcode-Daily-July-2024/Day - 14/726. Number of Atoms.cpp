class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();  // Length of the formula string
        unordered_map<string, int> result_counter;  // Map to store final atom counts
        stack<unordered_map<string, int>> parenthesis_stack;  // Stack to handle nested parentheses
        int cur_ind = 0;  // Current index in the formula string

        while (cur_ind < n) {
            char cur_char = formula[cur_ind];  // Current character in the formula

            if (cur_char == '(') {  // Handle opening parenthesis
                cur_ind++;
                parenthesis_stack.push(unordered_map<string, int>());  // Push a new map onto the stack
                continue;
            }

            if (cur_char == ')') {  // Handle closing parenthesis
                string mult_str = "";
                cur_ind++;

                // Extract multiplier after closing parenthesis
                while (cur_ind < n && isdigit(formula[cur_ind])) {
                    mult_str += formula[cur_ind];
                    cur_ind++;
                }

                int mult = mult_str.empty() ? 1 : stoi(mult_str);  // Default multiplier is 1 if not specified
                unordered_map<string, int> last_counter = parenthesis_stack.top();  // Get the map on top of the stack
                parenthesis_stack.pop();
                unordered_map<string, int>& target = parenthesis_stack.empty() ? result_counter : parenthesis_stack.top();  // Determine target map
                
                // Multiply counts in the popped map and add them to the target map
                for (const auto& [elem, counter] : last_counter) {
                    target[elem] += counter * mult;
                }
                continue;
            }

            string cur_elem = "";  // Current element name
            string cur_counter_str = "";  // Current element count as string
            unordered_map<string, int>& target = parenthesis_stack.empty() ? result_counter : parenthesis_stack.top();  // Determine target map

            // Parse element names and their counts
            while (cur_ind < n && formula[cur_ind] != '(' && formula[cur_ind] != ')') {
                if (isalpha(formula[cur_ind])) {  // Handle alphabetical characters
                    if (isupper(formula[cur_ind]) && !cur_elem.empty()) {
                        target[cur_elem] += cur_counter_str.empty() ? 1 : stoi(cur_counter_str);  // Add previous element count to target map
                        cur_elem = "";  // Reset for next element
                        cur_counter_str = "";  // Reset for next element count
                    }
                    cur_elem += formula[cur_ind];
                } else {  // Handle numerical characters
                    cur_counter_str += formula[cur_ind];
                }
                cur_ind++;
            }

            // Add the last parsed element and its count to the target map
            target[cur_elem] += cur_counter_str.empty() ? 1 : stoi(cur_counter_str);
        }

        vector<string> parts;  // Vector to store result parts
        // Convert map entries to strings and add them to the vector
        for (const auto& [elem, counter] : result_counter) {
            parts.push_back(elem + (counter == 1 ? "" : to_string(counter)));
        }
        sort(parts.begin(), parts.end());  // Sort the parts lexicographically

        string result;  // Final result string
        // Concatenate sorted parts into the result string
        for (const auto& part : parts) {
            result += part;
        }

        return result;  // Return the final result
    }
};
