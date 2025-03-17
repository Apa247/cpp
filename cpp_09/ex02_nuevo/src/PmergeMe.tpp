/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:36:54 by daparici          #+#    #+#             */
/*   Updated: 2025/03/17 17:57:34 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

template <typename T, template <typename, typename> class Container>
PmergeMe<T, Container>::PmergeMe() {}

template <typename T, template <typename, typename> class Container>
PmergeMe<T, Container>::PmergeMe(const PmergeMe<T, Container> &src) {
	*this = src;
}

template <typename T, template <typename, typename> class Container>
PmergeMe<T, Container>	&PmergeMe<T, Container>::operator =(const PmergeMe<T, Container> &src)
{
	if (this != &src)
	*this = src;
	return *this;
}


template <typename T, template <typename, typename> class Container>
PmergeMe<T, Container>::~PmergeMe() {}

template <typename T>
bool reserve(T &container, typename T::size_type size)
{
	(void)container;
	(void)size;
	return false;
}

template <typename T, typename U>
bool reserve(std::vector<T, U> &container, typename std::vector<T, U>::size_type size)
{
	container.reserve(size);
	return true;
}



// Algoritmo de ordenamiento Merge-insertion
// Source: https://en.wikipedia.org/wiki/Merge-insertion_sort




// Para Deque 

template <typename T>
std::deque<std::pair<T, T> > merge(std::deque<std::pair<T, T> > left, std::deque<std::pair<T, T> > right)
{
    std::deque<std::pair<T, T> > pairs;

    while(left.size() && right.size())
    {
        if (left[0].first < right[0].first)
        {
            pairs.push_back(left[0]);
            left.pop_front();
        }
        else
        {
            pairs.push_back(right[0]);
            right.pop_front();
        }
    }

    while(left.size())
    {
        pairs.push_back(left[0]);
        left.pop_front();
    }

    while(right.size())
    {
        pairs.push_back(right[0]);
        right.pop_front();
    }
    return pairs;
}

template <typename T>
std::deque<std::pair<T, T> > sort_pairs(std::deque<std::pair<T, T> > &pairs)
{
    if (pairs.size() <= 1)
        return pairs;
        
    std::deque<std::pair<T, T> > first;
    std::copy(pairs.begin(), pairs.begin() + pairs.size() / 2, std::back_inserter(first));

    std::deque<std::pair<T, T> > second;
    std::copy(pairs.begin() + pairs.size() / 2, pairs.end(), std::back_inserter(second));

    return merge(sort_pairs(first), sort_pairs(second));
}

template <typename T>
std::deque<T> binary_search_insertion(std::deque<T> &array, size_t start, T item)
{
    if (array.empty())
    {
        array.push_back(item);
        return array;
    }

    size_t left = start;
    size_t right = array.size() - 1;

    bool at_start = (left < array.size()) && (array[left] > item);

    while (left <= right && !at_start)
    {
        size_t middle = (left + right) / 2;

        if (left == right)
        {
            if (array[middle] < item)
                left = middle + 1;
            break;
        }
        else if (array[middle] < item)
            left = middle + 1;
        else
            right = middle - 1;
    }
    if (left > array.size() - 1)
        array.insert(array.end(), item);
    else
        array.insert(array.begin() + left, item);
        
    if (VERBOSE)
    {
        if (left > 0)
            std::cout << "Inserting " << item << " at position " << left << " (after " << array[left - 1] << ")" << std::endl;
        else
            std::cout << "Inserting " << item << " at position " << left << " (at the beginning)" << std::endl;
    }
    return array;
}

template <typename T, template <typename, typename> class Container>
std::deque<T> PmergeMe<T, Container>::sort(const std::deque<T> &array) const 
{
	if (array.size() < 2)
		return array;

	bool is_odd = array.size() % 2 != 0;
	
	std::deque<std::pair<T, T> > pairs;
	for (size_t i = 0; i < array.size(); i += 2) {
		if (i + 1 >= array.size())
			continue; // Ignorar el último elemento impar.
		else if (array[i] > array[i + 1])
			pairs.push_back(std::make_pair(array[i + 1], array[i]));
		else
			pairs.push_back(std::make_pair(array[i], array[i + 1]));
	}
	
	if (VERBOSE) {
		std::cout << "Pairs: ";
		for (size_t i = 0; i < pairs.size(); i++)
			std::cout << "[" << pairs[i].first << ", " << pairs[i].second << "], ";
		std::cout << std::endl;
	}

	std::deque<std::pair<T, T> > pairs_sorted = sort_pairs(pairs);

	if (VERBOSE) {
		std::cout << "Pair sorted: ";
		for (size_t i = 0; i < pairs_sorted.size(); i++)
			std::cout << "[" << pairs_sorted[i].first << ", " << pairs_sorted[i].second << "], ";
		std::cout << std::endl;
	}

	std::deque<T> sorted;
	for (size_t i = 0; i < pairs_sorted.size(); i++)
		sorted.push_back(pairs_sorted[i].first);

	if (VERBOSE) {
		std::cout << "Sorted: [";
		for (size_t i = 0; i < sorted.size(); i++)
			std::cout << sorted[i] << ", ";
		std::cout << "]"<< std::endl;
	}

	if (is_odd)
		binary_search_insertion(sorted, 0, array.back());
	
	for (size_t i = 0; i < pairs_sorted.size(); i++) {
		binary_search_insertion(sorted, i, pairs_sorted[i].second);

		if (VERBOSE) {
			std::cout << "Partial: [";
			for (size_t i = 0; i < sorted.size(); i++)
				std::cout << sorted[i] << ", ";
			std::cout << "]" << std::endl;
		}
	}

	return sorted;
}

// Para Vector

template <typename T>
std::vector<std::pair<T, T> > merge(std::vector<std::pair<T, T> > left, std::vector<std::pair<T, T> > right)
{
    std::vector<std::pair<T, T> > pairs;
    pairs.reserve(left.size() + right.size());

    while(left.size() && right.size())
    {
        if (left[0].first < right[0].first)
        {
            pairs.push_back(left[0]);
            left.erase(left.begin());
        }
        else
        {
            pairs.push_back(right[0]);
            right.erase(right.begin());
        }
    }

    while(left.size())
    {
        pairs.push_back(left[0]);
        left.erase(left.begin());
    }

    while(right.size())
    {
        pairs.push_back(right[0]);
        right.erase(right.begin());
    }
    return pairs;
}

template <typename T>
std::vector<std::pair<T, T> > sort_pairs(std::vector<std::pair<T, T> > &pairs)
{
    if (pairs.size() <= 1)
        return pairs;
        
    std::vector<std::pair<T, T> > first;
    std::copy(pairs.begin(), pairs.begin() + pairs.size() / 2, std::back_inserter(first));

    std::vector<std::pair<T, T> > second;
    std::copy(pairs.begin() + pairs.size() / 2, pairs.end(), std::back_inserter(second));

    return merge(sort_pairs(first), sort_pairs(second));
}

template <typename T>
std::vector<T> binary_search_insertion(std::vector<T> &array, size_t start, T item)
{
    if (array.empty())
    {
        array.push_back(item);
        return array;
    }

    size_t left = start;
    size_t right = array.size() - 1;

    bool at_start = (left < array.size()) && (array[left] > item);

    while (left <= right && !at_start)
    {
        size_t middle = (left + right) / 2;

        if (left == right)
        {
            if (array[middle] < item)
                left = middle + 1;
            break;
        }
        else if (array[middle] < item)
            left = middle + 1;
        else
            right = middle - 1;
    }
    if (left > array.size() - 1)
        array.insert(array.end(), item);
    else
        array.insert(array.begin() + left, item);
        
    if (VERBOSE)
    {
        if (left > 0)
            std::cout << "Inserting " << item << " at position " << left << " (after " << array[left - 1] << ")" << std::endl;
        else
            std::cout << "Inserting " << item << " at position " << left << " (at the beginning)" << std::endl;
    }
    return array;
}

template <typename T, template <typename, typename> class Container>
std::vector<T> PmergeMe<T, Container>::sort(const std::vector<T> &array) const 
{
	if (array.size() < 2)
		return array;

	bool is_odd = array.size() % 2 != 0;
	
	std::vector<std::pair<T, T> > pairs;
	pairs.reserve(array.size() / 2 + 1);
	for (size_t i = 0; i < array.size(); i += 2) {
		if (i + 1 >= array.size())
			continue; // Ignorar el último elemento impar.
		else if (array[i] > array[i + 1])
			pairs.push_back(std::make_pair(array[i + 1], array[i]));
		else
			pairs.push_back(std::make_pair(array[i], array[i + 1]));
	}
	
	if (VERBOSE) {
		std::cout << "Pairs: ";
		for (size_t i = 0; i < pairs.size(); i++)
			std::cout << "[" << pairs[i].first << ", " << pairs[i].second << "], ";
		std::cout << std::endl;
	}

	std::vector<std::pair<T, T> > pairs_sorted = sort_pairs(pairs);

	if (VERBOSE) {
		std::cout << "Pair sorted: ";
		for (size_t i = 0; i < pairs_sorted.size(); i++)
			std::cout << "[" << pairs_sorted[i].first << ", " << pairs_sorted[i].second << "], ";
		std::cout << std::endl;
	}

	std::vector<T> sorted;
	sorted.reserve(pairs_sorted.size());
	for (size_t i = 0; i < pairs_sorted.size(); i++)
		sorted.push_back(pairs_sorted[i].first);

	if (VERBOSE) {
		std::cout << "Sorted: [";
		for (size_t i = 0; i < sorted.size(); i++)
			std::cout << sorted[i] << ", ";
		std::cout << "]"<< std::endl;
	}

	if (is_odd)
		binary_search_insertion(sorted, 0, array.back());
	
	for (size_t i = 0; i < pairs_sorted.size(); i++) {
		binary_search_insertion(sorted, i, pairs_sorted[i].second);

		if (VERBOSE) {
			std::cout << "Partial: [";
			for (size_t i = 0; i < sorted.size(); i++)
				std::cout << sorted[i] << ", ";
			std::cout << "]" << std::endl;
		}
	}

	return sorted;
}